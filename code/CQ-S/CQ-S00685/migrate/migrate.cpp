#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cerr<<#x<<':'<<x<<endl
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=2e6+5;
int c,T;
int n,d;
int x[N];
int f[N],g[N],cnt[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(c<=10){
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int i=0;i<=n;i++) f[i]=g[i]=cnt[i]=0;
			cnt[0]=1;
			f[l]=0,g[l]=1;
			int p=l;
			for(int i=l+1;i<=n;i++){
				while(x[p]+d<x[i]) cnt[f[p]]-=g[p],p++;
				f[i]=f[p]+1;
				g[i]=cnt[f[p]];
				cnt[f[i]]+=g[i];
				if(g[i]==2){
					ans++;
				}
//				cout<<l<<' '<<p<<' '<<i<<' '<<f[i]<<' '<<g[i]<<endl;
			}
		}
		cout<<ans<<endl;
		return;
	}
	if(c<=12){
		for(int i=0;i<=n;i++) f[i]=g[i]=cnt[i]=0;
		cnt[0]=1;
		f[1]=0,g[1]=1;
		int p=1;
		for(int i=2;i<=n;i++){
			while(x[p]+d<x[i]) cnt[f[p]]-=g[p],p++;
			f[i]=f[p]+1;
			g[i]=cnt[f[p]];
			cnt[f[i]]+=g[i];
			if(g[i]==2){
				cout<<n-i+1<<endl;
				return;
			}
//			cout<<l<<' '<<p<<' '<<i<<' '<<f[i]<<' '<<g[i]<<endl;
		}
		cout<<0<<endl;
		return;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IOS;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

