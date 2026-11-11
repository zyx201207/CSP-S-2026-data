#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e6+5;
ll a[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,T; cin>>c>>T;
	while(T--){
		int n,d; ll ans=0,cnt=0; cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
		int k=a[2]-a[1],len=d/k;
		if(k>d){
			cout<<0<<'\n';
			continue;
		}
		if(n>=2*len) ans=n-2*len+1;
		cout<<ans<<'\n';
		}
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				if(a[r]-a[r-1]>d&&cnt<d) break;
				cnt+=a[r]-a[r-1];
				if(cnt>=2*d){ 
					ans+=n-r; break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
