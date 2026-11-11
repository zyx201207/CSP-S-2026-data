#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[1000085];
		ll n,d;
int minn=1e9,var=0;
void dfs(int l,int r,int dq,int step){
	if(dq==r){
		if(step<minn){
			minn=step;
			var=1;
		}else if(step==minn){
			var++;
		}
		return ;
	}
      for(int i=dq+1;i<=r;i++){
		  if(a[i]-a[dq]<=d)dfs(l,r,i,step+1);
	  }	
	  return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//最优策略一定是尽量跳
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
	    for(ll i=1;i<=n;i++)cin>>a[i];
	    int ans=0;
		for(ll i=1;i<=n;i++){
		   for(ll j=i+1;j<=n;j++){
			   minn=1e9;
			   var=0;
			   dfs(i,j,i,0);
			   if(var==2)ans++;
		   }	
		}
		cout<<ans<<endl;
	}
    return 0;
}
//Oct31==Dec25?
