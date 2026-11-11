#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2*1e6+100;
int c,t,n,d,ans;
int x[MAXN],cnt[MAXN];
bool vis[MAXN];
void iddfs(int dep,int step,int p) {
//	cerr<<"depth="<<dep<<" step="<<step<<" visited "<<p<<'\n';
	if(step==dep) {
		if(vis[p]==0) {
			cnt[p]++;
//			cerr<<"cnt_"<<p<<" ++ -> ="<<cnt[p]<<'\n';
		}
//		cerr<<"RETURNED\n";
		return;
	}
	for(int i=p+1; i<=n; i++) {
		if(x[i]-x[p]<=d)iddfs(dep,step+1,i);
		else break;
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
			cnt[i]=0;
			vis[i]=0;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				cnt[j]=0;
				vis[j]=0;
			}
			for(int dep=1; dep<=n-i+1; dep++) {
				cerr<<dep;
				iddfs(dep,0,i);
				for(int j=i+1; cnt[j]!=0; j++) {
//					cerr<<"cnt_"<<j<<"="<<cnt[j]<<'\n';
					if(cnt[j]==2 and vis[j]==0) {
						ans++;
//						cerr<<"ans:"<<ans<<' '<<i<<' '<<j<<'\n';
					}
					vis[j]=1;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}