#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,m,a[N],ans;
int tmp[N],cnt;
long long maxa;
bool cmp(long long x,long long y){return x>=y;}
void dfs(long long x,long long sum,long long y)
{
	if(y==m) ans=max(ans,sum);
	if(x>n){return;}
	dfs(x+1,((y!=0)?sum:a[x])&a[x],y+1);
	dfs(x+1,sum,y);
	return;
}
void solve1(){dfs(1,0,0);return;}
void solve2(){for(int i=1;i<=n;i++) ans=max(ans,a[i]);return;}
void solve3()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,a[i]&a[j]);
		}
	}
	return;
}
void solve4(){ans=a[1]; for(int i=2;i<=n;i++) ans&=a[i];return;}
void solve5(){sort(a+1,a+n+1,cmp); for(int i=1;i<=m;i++) ans&=a[i];return;}
void solve()
{
	cin>>n>>m; for(int i=1;i<=n;i++) cin>>a[i],maxa=max(maxa,a[i]);
	if(m==1) solve2();
	else if(m==n) solve4();
	else if(n<=20) solve1();
	else if(m==2) solve3();
	else if(maxa<N) solve5();
	cout<<ans; ans=0;
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
} 
