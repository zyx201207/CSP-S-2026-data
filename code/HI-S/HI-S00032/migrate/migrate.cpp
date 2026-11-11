#include <bits/stdc++.h>

using namespace std;

const int N = 300+10;

#define ll long long

int n, ls[N], rs[N];
ll d, x[N], dp[N][N][N]; 

ll dis(int a, int b) {
	return abs(x[a]-x[b]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c, t; cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
		}
		for(int i=1;i<=n;i++) {
			ls[i]=i, rs[i]=i;
			for(int j=i-1;j>=1;j--) {
				if(dis(j,i)<=d)ls[i]=j;
				else break;
			}
			for(int j=i+1;j<=n;j++) {
				if(dis(j,i)<=d)rs[i]=j;
				else break;
			}
		}
		for(int k=0;k<=n;k++) {
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					if(k==0) {
						if(i==j)dp[i][j][k]=1;
						else dp[i][j][k]=0; 
						continue;
					} 
					dp[i][j][k]=0;
					for(int p=ls[i];p<=rs[i];p++) {
						dp[i][j][k]+=dp[p][j][k-1];
						if(dp[i][j][k]>=1e4)dp[i][j][k]=1e4;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				int v=0, k=i;
				bool flag=true;
				while(1) {
					++v; 
					if(rs[k]>=j) {
						break;
					}
					if(k==rs[k]) {
						flag=false;
						break;
					}
					k=rs[k];
				}
				if(!flag)continue;
				if(dp[i][j][v]==2)++ans;
			}
		}	
		cout<<ans<<"\n";
	}
	return 0;
}
