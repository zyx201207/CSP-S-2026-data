#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000006],dis[1005][1005],gt[1005][1005];
int ans;
void dfs(int now,int ds,int st) {
	if(ds==dis[st][now]) {
		gt[st][now]++;
	} else {
		return;
	}
	for(int i=now+1; i<=n; i++) {
		if(x[i]-x[now]<=d)dfs(i,ds+1,st);
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		memset(dis,0x3f,sizeof(dis));
		memset(gt,0,sizeof(gt));
		if(c<=2) {
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					int cnt=1,l=i;
					for(int k=i+1; k<=j; k++) {
						if(x[k]-x[k-1]>d) {
							break;
						}
						if(x[k]-x[l]>d) {
							cnt++;
							l=k-1;
						}
					}
					dis[i][j]=cnt;
				}
				dis[i][i]=0;
			}
			for(int i=1; i<=n; i++) {
				dfs(i,0,i);
			}
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					if(gt[i][j]==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
}/*
24pts
//freopen
ok
*/
