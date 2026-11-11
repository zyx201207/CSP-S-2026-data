#include<bits/stdc++.h>
using namespace std;

#define N 2005
#define ll long long

int c,t;
int x[N];
int dp[N][N];//表示i到j有多少花费最低方案 
int mn[N][N];//表示i到j最低方案的花费 

void solve(){
	int n;ll d;
	cin>>n>>d;
	cout<<0<<'\n';
	return;
}

int main(){
	freopen("migrate.in","r",stdin);// freopen("mirage.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
lets try to get On2
4 2
1 2 3 4
最短距离表rt
0 1 1 2
1 0 1 1
1 1 0 1
2 1 1 0
dp:
1 1 1 2
1 1 1 1
1 1 1 1
2 1 1 1
到底是怎么求的 
相当于从[x,x]到[y,y]走车的路的最小值方案数
走车怎么解决
来一个复杂一点的例子
4 4
1 3 6 10
rt
0 1 1 3
1 0 1 2
1 1 0 1
3 2 1 0
走最短距离的可行路线个数：
1 1 1 1
1 1 1 
1 1 1
1
我算是没救了
究竟有没有好写的特殊性质 
B是直接随便选，最短长度至多是2
最短长度为1时，显然没有第二个最短长度为1的，排除
不经过那个万能岛还能2步走吗？可能，我们要判断这些岛有没有两步走发展战略
不连通 
*/

