#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
ll n,m,ans,mxi,mxj;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;vl a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2){
		ans=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
	}else if(m==1){
		ans=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==n){
		for(int i=1;i<=n;i++){
			ans=(ans&a[i]);
		}
	}else if((n&(n-1))==0){
		cout<<0<<'\n';
	}else{
		ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			ans=min(ans,a[i]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
