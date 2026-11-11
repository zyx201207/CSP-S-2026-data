#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =2e6+10;
ll x[N],f[400][400];ll c,t,n,d;
bool check(){
	if(n==2) return true;
	ll l = x[2]-x[1];
	for(int i = 3;i<=n;i++)
		if(x[i]-x[i-1]!=l) return false;
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++) cin>>x[i];
		if(check()){
			ll l=x[2]-x[1];ll k;
			k=d/l;
			if(k==0||k==1){
				cout<<0<<endl;
			}
			else{
				ll ans=n-(2*k-1);
				if(ans<0) cout<<0<<endl;
				else cout<<ans<<endl;
			}
		}
		else{
			for(int l=1;l<=n;l++){
				for(int r=l;r<=n;r++){
					ll dis=x[r]-x[l];
					if(dis%d==0) f[l][r]=dis/d;
					else f[l][r]=dis/d+1;
				}
			}
			int ans=0;
			for(int l=1;l<=n;l++){
				for(int r=l+2;r<=n;r++){
					if(f[l][r]<=1)continue;
					int tot=0;
					for(int k=l+1;k<r;k++)
						if(f[l][k]+f[k][r]==f[l][r]) tot++;
					if(tot==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
