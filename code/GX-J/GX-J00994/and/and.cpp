#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
ll n,m,a[2*100010],ans;
void dfs(ll k,ll t,ll f)
{
	if(t==0) {ans=max(ans,f); return;}
	if(k>n) return;
	if(n-k+1<t) return;
	if(t==m) {dfs(k+1,t-1,a[k]); dfs(k+1,t,f);}
	else {dfs(k+1,t-1,f&a[k]); dfs(k+1,t,f);}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(m==1)
		{for(int i=1;i<=n;i++) ans=max(ans,a[i]); cout<<ans; return 0;}
	if(m==n)
		{ans=a[1]; for(int i=2;i<=n;i++) ans=ans&a[i]; cout<<ans; return 0;}
	if(m==2)
		{for(int i=1;i<=n;i++) 
				for(int j=i+1;j<=n;j++)
				{
					ll q=a[i]&a[j];
					ans=max(ans,q); 
				}
		cout<<ans; return 0;}
	if(m==n-1){
			for(int i=1;i<=n;i++)
			{
				ll k=-1;
				for(int j=1;j<=n;j++)
					if(i==j) continue;
					else if(k==-1) k=a[j];
					else k=k&a[j];
				ans=max(ans,k);
			}
			cout<<ans;}
				
	dfs(1,m,0);
	cout<<ans;
	return 0;
}
