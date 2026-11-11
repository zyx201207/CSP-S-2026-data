#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;

int c,t;
ll to(ll s,ll d,ll n,ll x[N]){
	ll l=1,r=s,ans=s;
	while(l<=r){
		ll mid=(l+r)/2;
		if(x[s]-x[mid]<=d){ans=mid;r=mid-1;}
		else{l=mid+1;}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d,x[N]={},dis[N]={},ans=0;
		bool b[N]={};
		cin>>n>>d;
		for(int i=1;i<=n;i++){cin>>x[i];}
		for(int i=1;i<=n;i++){
			ll fl=to(i,d,n,x);
			if(fl==i){dis[i]=1;b[i]=1;continue;}
			for(int j=fl;j<i;j++){
				dis[i]+=dis[j];
			}
		}
		ll i=1,j=1;
		while(j<=n){
			if(dis[j]*1.0/dis[i]<2){j++;}
			else if(dis[j]*1.0/dis[i]==2){ans++;i++;}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
