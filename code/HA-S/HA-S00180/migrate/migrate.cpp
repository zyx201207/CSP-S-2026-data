#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll C,T;
ll n,d;
ll a[2100000];
ll ans;

void solve(){
	ans=0;
	cin>>n>>d;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		ll k=i+3,cnt=0;
		while (a[k]-a[i]<=d&&k<=n) k++;
		while (k<=n){
			if (a[k]-a[i]>=d*2) break;
			cnt=0;
			for (int j=i+1;j<k;j++){
				if (a[j]-a[i]<=d&&a[k]-a[j]<=d) cnt++;
			}
			if (cnt==2){
				ll l=i-1,r=k+1;
				ll al=1,ar=1;
				while (l>=1){
					if (a[l+2]-a[l]>d&&a[l+1]-a[l]<=d){
							al++;
							l--;
					}else break;
				}
				while (r<=n){
					if (a[r]-a[r-2]>d&&a[r]-a[r-1]<=d){
						ar++;
						r++;
					}else break;
				}
				ans+=al*ar;
			}
			k++;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while (T--) solve();
	return 0;
}


