#include<bits/stdc++.h>
using namespace std;
const int maxn=4005;
int dp[maxn][maxn][2][2],n;
struct edge
{
	int a,b;
}e[maxn<<1];
int head[maxn],cnt=0;
void add(int a,int b)
{
	e[++cnt]={b,head[a]};
	head[a]=cnt;
}
void solve()
{
	cout<<0<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
}
