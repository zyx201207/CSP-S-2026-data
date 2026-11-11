#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
bool vis[200005];
ll ans=0;
ll n,m,maxx=-1;
void dfs(ll step,ll sum){
	if(step==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
		    if(step==0){
			    vis[i]=1;
			    dfs(step+1,a[i]);
			    vis[i]=0;
		    }else{
		    	vis[i]=1;
			    dfs(step+1,(sum&a[i]));
			    vis[i]=0;
		   }
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    
    cin>>n>>m;
    bool flagA=1,flagB=1;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	maxx=max(maxx,a[i]);
		if((a[i]!=a[i-1]+1)&& i>=2)flagB=false;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(flagB==true){
		cout<<n-m<<" ";
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
