#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
typedef long long ll;
int n,c;
ll d,a[N],f[N],dis[N];
ll bsum[N];

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll ans=0;
	if(c==11 || c==12){
		for(int i=1;i>=1;i--){
			fill(f+1,f+n+1,0);
			f[i]=1;
			fill(dis+1,dis+n+1,INT_MAX);
			dis[i]=0;
			fill(bsum,bsum+n+1,0);
			int pos=i;
			bsum[0]++;
			for(int j=i+1;j<=n;j++){
				while(pos<j && a[j]-a[pos]>d){
					bsum[dis[pos]]-=f[pos];
					++pos;
				}
				if(pos==j) break;
				dis[j]=dis[pos]+1;
				f[j]=bsum[dis[j]-1];
				if(f[j]==2) ans+=1ll*n-j+1;
				bsum[dis[j]]+=f[j];
			}
		}
		cout<<ans<<'\n';
		return;
	}
	for(int i=n;i>=1;i--){
		fill(f+1,f+n+1,0);
		f[i]=1;
		fill(dis+1,dis+n+1,INT_MAX);
		dis[i]=0;
		fill(bsum,bsum+n+1,0);
		int pos=i;
		bsum[0]++;
		for(int j=i+1;j<=n;j++){
			while(pos<j && a[j]-a[pos]>d){
				bsum[dis[pos]]-=f[pos];
				++pos;
			}
			if(pos==j) break;
			dis[j]=dis[pos]+1;
			f[j]=bsum[dis[j]-1];
			if(f[j]==2) ans++;
			bsum[dis[j]]+=f[j];
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}