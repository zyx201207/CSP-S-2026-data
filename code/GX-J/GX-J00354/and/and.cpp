#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
using namespace std;
typedef long long ll;
const ll N=2e5+10,G=5e2+8,inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
ll a[N];
ll ok[N],pl[N];
ll maxx,all=a[1];
ll ans;
void dfs(int x,int sum)
{
	if(x>n) return;
	if(sum>=m)
	{
		ll num=-1;
		f(i,1,n)
		{
			if(ok[i] && num==-1) num=a[i];
			else if(ok[i]) num=(num&a[i]);
		}
		ans=max(ans,num);
		return;
	}
	ok[x]=1;
	dfs(x+1,sum+1);
	ok[x]=0;
	dfs(x+1,sum);
	return;
}
void solve1()
{
	dfs(1,0);
}
void solve2()
{
	f(i,1,n)
	{
		ll num=a[i];
		f(j,1,n)
		{
			if(i==j) continue;
			ans=max(ans,(num&a[j]));
		}
	}
}
void solve3()
{
	f(i,1,n) ans=max(ans,(all&a[i]));
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	f(i,1,n)
	{
		cin>>a[i];
		maxx=max(a[i],maxx);
		if(i>1) all=(all & a[i]);
	}
	if(m==1) cout<<maxx;
	else if(m==n) cout<<all;
	else if(n<=20) solve1();
	else if(m==2) solve2();
	else if(m==n-1) solve3();
	cout<<ans;
	return 0;
}













































