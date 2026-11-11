#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+10,M=1e4+10;
ll c,t,n,d,a[N],f[M][M],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				f[i][j]=0;
			}
		}
		ans=0;
		for(ll i=2,l=1;i<=n;i++){
			while(l<i&&a[i]-a[l]>d) l++;
			if(l<i){
				for(ll j=1;j<l;j++){
					f[j][i]=f[j][l]+1;
					if(l<=i-2&&f[j][l+1]==f[j][l]&&f[j][l+2]!=f[j][l]) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
