#include <iostream>
using namespace std;
int 
int main(){
	/*
	使用数组 f1[i] 记录从 i 岛前往 i+1...n 岛需要的最短路径长度
	使用数组 f2[i] 记录从 i 岛前往 i+1...n 岛最短路径的数量
	第一层循环 循环初始岛 i
	第二层循环 循环目的岛 j
	第三层循环 循环借助的岛 k
	如果从 i 岛 借助 岛 k 到达 岛 j 长度更小，则 f2[j] = 1, 设置f1[j]
	如果从 i 岛 借助 岛 k 到达 岛 j 长度相等，则 f2[j]++ 
	*/
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int n, t, co
}
