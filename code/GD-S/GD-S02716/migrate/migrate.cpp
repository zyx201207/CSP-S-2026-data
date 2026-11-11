#include<bits/stdc++.h>
using namespace std;
const int mx=18;
const int mod =998244353;
#define ll long long
ll f[mx][mx];
ll a[mx];
void solve(){
	ll n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i][i]=0;
//		if(i<n)f[i][i+1]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d)f[i][j]=1;
			else break;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i+1;k<j;k++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
//			cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
		}
	}
	ll ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int cnt=0;
			for(int k=i+1;k<j;k++){
				if(f[i][k]+f[k][j]==f[i][j])cnt++;
			}
			if(cnt==2){
//				cout<<i<<" "<<j<<'\n';
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1,c;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}


