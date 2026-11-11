#include<bits/stdc++.h>
//特殊性质 A：x 1 ,x 2 ,...,x n 构成等差数列。
//特殊性质 B：存在一座岛屿，使得海鸟可以从该岛屿直接飞到任意其他岛屿。
//特殊性质 C：x n ? x 1 ≤ 10d。

using namespace std;

int c,t,n;

long long d;

long long x[2000005];
int dp[2000005];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	cin >> c >>t;
	for (int i=1;i<=t;i++) {
		cin >> n >> d;
		for (int j=1;j<=n;j++)  {
		    cin >>x[i];
		}
	}
	return 0;
}
//若从第 u 座岛屿到第 v 座岛屿
//.
//恰
//.
//好有两条，海鸟可以分成两
//群，分别沿其中一条飞往第 v 座岛屿；此时称 (u,v) 为
//
//双//
//.
//径
//.
//岛
//.
//屿
//.
//对。两条路径不同，
//当且仅当它们经过的岛屿序列不完全相同。
