#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,t,n,d;
ll a[N];
ll f(ll l,ll r){
	if(a[r]-a[l]<=d) return 1;
	for(int i=l+1;i<r;i++){
		return f(l,i)+f(i,r);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll nn=-1,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]>d){
				nn=i-1;
			}
		}
		if(nn!=-1) n=nn;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(f(i,j)==d)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
