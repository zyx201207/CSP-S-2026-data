#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans;
bool g[200005];
void dfs(ll x,ll sum,ll s){
	if(x==m){
		ans=max(ans,sum);
		return ;
	}
	for(ll i=s+1;i<=n;i++){
		if(g[i])continue;
		else {
			g[i]=true;
			dfs(x+1,sum&a[i],i);
			g[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(ll i=1;i<=n;i++)
		cin>>a[i];
		
	for(ll i=1;i<=n;i++){
		g[i]=true;
		dfs(1,a[i],i);
		g[i]=false;
	}
	
	cout<<ans;
	
	return 0;
} 
