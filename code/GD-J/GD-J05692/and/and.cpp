#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[200010]={};
ll now[200005]={};
ll ans=-1,maxx=-1,sumand=(1<<35)-1,dousum=-1;
ll dfs(ll cur,ll x , ll sum)
{
	if(n-x<m-cur-1) return -1;
	if(cur==m) return sum;
	return max(dfs(cur+1,x+1,sum&a[x]),dfs(cur,x+1,sum));
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sumand=sumand&a[i];
	}
	if(m==1) cout<<maxx;
	if(m==n) cout<<sumand;
	if(m==2){
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++){
				dousum=max(a[i]&a[j],dousum);
			}
		}
		cout<<dousum;
	}
	else cout<<dfs(0,1,(1<<35)-1);
	return 0; 
 } 
