#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll c,t,n,d,minn,ans,k;
ll a[2000005];
void dfs(ll s,ll e,ll val){
	//cout<<s<<" "<<e<<" "<<val<<" "<<k<<" "<<minn<<'\n';
	if(s>=e){
		if(s==e){
			if(val<minn){
				k=1;
				minn=val;
			}else if(val==minn){
				k++;
			}
		}
		return;
	}
	ll u=upper_bound(a+1,a+n+2,a[s]+d)-a-1;
	for(int i=s+1;i<=u&&i<=e;i++){
		dfs(i,e,val+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		a[n+1]=2e18;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				k=0;
				minn=2e18;
				dfs(j,i,0);
				if(k==2){
					ans++;
					//cout<<i<<" "<<j<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
