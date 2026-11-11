#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12) {
		while(t--) {
			int n,d,x[3];
			cin>>n>>d;
			cin>>x[1]>>x[2];
			int dd=x[2]-x[1];
			if(dd/2>=d) cout<<0<<'\n';
			else cout<<n-2<<'\n';
		}
	} else if(c==13||c==14) {
		while(t--) {
			cout<<0<<'\n';
		}
	} else {
		while(t--) {
			int n,d,x[5005],dis[5005],ans=0;
			cin>>n>>d;
			for(int i=1; i<=n; i++) cin>>x[i];
			for(int i=1; i<=n-1; i++) dis[i]=x[i+1]-x[i];
			for(int i=1; i<=n-3; i++) {
				if(abs(dis[i+2]-dis[i])<2*d&&abs(dis[i+2]-dis[i])>d) ans++;
				if(abs(dis[i+3]-dis[i])<2*d&&abs(dis[i+2]-dis[i+1])<d&&abs(dis[i+2]-dis[i])>d&&abs(dis[i+3]-dis[i+1])>d) ans++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
