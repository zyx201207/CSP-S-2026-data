#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define of(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define N 210510
using namespace std;
int n,m,ans=-1;
ll a[N];
void dfs(int x,int tot,int p)
{
	if(tot==m) 
	{
		ans=max(ans,x);
		return;
	}
	if(p==n) return;
	fo(i,p+1,n+tot-m+1)
		dfs(x&a[i],tot+1,i);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	fo(i,1,n) cin>>a[i];
	if(m==n)
	{
		ans=a[1];
		fo(i,2,n) ans&=a[i];
		cout<<ans;
		return 0;
	}
	fo(i,1,n-m+1) dfs(a[i],1,i);
	cout<<ans;
	return 0;
}
