#include <stdio.h>
#include <math.h>

// 斯特藩-玻尔兹曼常数
#define SIGMA 5.670374419e-8  // W/(m²·K⁴)

// 计算所需辐射面积（单位：平方米）
double calculateRadiationArea(double Q, double epsilon, double T_surface, double T_ambient) {
    double T4 = pow(T_surface, 4);
    double Ta4 = pow(T_ambient, 4);
    double area = Q / (epsilon * SIGMA * (T4 - Ta4));
    return area;
}

int main() {
    double Q = 100.0;                 // 散热功率需求，单位：W
    double epsilon = 0.85;           // 表面发射率
    double T_surface = 343.15;       // 表面温度 70°C = 343.15K
    double T_ambient = 298.15;       // 环境温度 25°C = 298.15K

    double area = calculateRadiationArea(Q, epsilon, T_surface, T_ambient);
    printf("所需辐射面积: %.6f m²\n", area);
    printf("折合 %.2f 平方厘米 (cm²)\n", area * 1e4);

    return 0;
}
