#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,v[100005],m,vmax=LLONG_MIN,vis[1000005],ho=LLONG_MAX;
void dfs(ll s){
	if(s>m){
		vmax=max(vmax,ho);
		
		//for(int i=1;i<=n;i++)cout<<vis[i]<<" "; 
		//cout<<ho<<endl;
		return;
	}
	for(ll i=s;i<=n;i++){
		if(vis[i]==0){
		ll op=ho;
		ho=ho&v[i];
		vis[i]=1;
		dfs(s+1);
		vis[i]=0;
		ho=op;	
		}
		
	}
	return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   // scanf("%lld,%lld,%lld,%lld",a,al,b,bl);
   cin>>n>>m;
   for(ll i=1;i<=n;i++){
   	cin>>v[i];
   }
   dfs(1);
   cout<<vmax;
    return 0;
}
