#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000005],dstce,tmp,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll i=1;i<=t;i++){
		cin>>n>>d;
		for(ll j=1;j<=n;j++){
			cin>>x[j];
		}
		dstce=x[2]-x[1];
		tmp=d/dstce;
		if(n/tmp<=1 || tmp<=1){
			cout<<0<<"\n";
			continue;
		}
		else{
			for(ll j=tmp+1;j<=n;j++){
				if(j%tmp==0) continue;
				ans+=n-j+1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
