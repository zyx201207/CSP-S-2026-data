#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[10000];
bool v[10000];
int minn[100][100];
int cnt[100][100][100],d;
void dfs(int n,int m) {
	if(m>n) {
		//for(int i=1;i<=n;i++) {
		//	cout<<v[i]<<" ";
		//}cout<<"\n \n";
		int one=0,s,t;
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(v[i]&&v[j]) {
					int dis=x[j]-x[i];
					if(dis>d) {
						//cout<<i<<" "<<j<<"?\n";
						return ;
					}
					break;
				}
			}
		}
		for(int i=1;i<=n;i++) {
			if(v[i]&&one==0) {
				s=i;
			}
			if(v[i]) one++;
		}
		for(int j=n;j>=1;j--) {
			if(v[j]) {
				t=j;
				break;
			}
		}
		if(s>=t||one==1) return ;
		//for(int i=1;i<=n;i++) {
		//	cout<<v[i]<<" ";
		//}cout<<"\n"<<s<<" "<<t<<" "<<one<<"\n";
		minn[s][t]=min(minn[s][t],one);
		cnt[s][t][one]++;
		return ;
	}
	v[m]=1;
	dfs(n,m+1);
	v[m]=0;
	dfs(n,m+1);
}
void solve() {
	int n;
	cin>>n>>d;
	for(int i=1;i<=n;i++) {
		cin>>x[i];
	}
	int ans=0;
	for(int i=1;i<=99;i++) {
		for(int j=1;j<=99;j++) {
			minn[i][j]=10;
		}
	}
	memset(cnt,0,sizeof cnt);
	dfs(n,1);
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(cnt[i][j][minn[i][j]]==2) {
				//cout<<i<<" "<<j<<" "<<minn[i][j]<<" "<<cnt[i][j][minn[i][j]]<<"\n";
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		solve();
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/
