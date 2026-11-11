#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=21e5,BN=305;
ll d,ans,x[N],mi[BN][BN],tot[BN][BN];
int c,t,n;
int main() {
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c >>t;
	while (t--) {
		memset (tot,0,sizeof(tot));
		memset (mi,0,sizeof(mi));
		ans=0;
		cin >>n >>d;
		for (int i=1; i<=n; i++) {
			cin >>x[i];
		}
		if (c<=6) {
			for (int i=1;i<=n;i++) {
				ll sum=0;
				for (int j=i+1;j<=n;j++) {
				/*	if (i==1 && j==3) {
						cout <<sum <<" " <<mi[i][j-1] <<"\n\n";
					}*/
					if (x[j]-x[i]>sum) {
						if (x[j]-x[i]>sum+d) mi[i][j]=N;
						else {
							mi[i][j]=mi[i][j-1]+1;
							sum+=d;
						}
					} else {
						mi[i][j]=mi[i][j-1];
					}
					if (mi[i][j]==1 && j-i==1) tot[i][j]=1;
					
				}
			}
	/*		for (int i=1;i<=n;i++) {
				for (int j=i+1;j<=n;j++) {
					cout <<tot[i][j] <<" ";
				}
				cout <<"\n";
			}*/
			for (int l=2;l<=n;l++) {
				for (int i=1;i+l<=n;i++) {
					if (mi[i][i+l]==N) continue;
					for (int j=1; j<l; j++) {
						if (mi[i][i+l]==mi[i][i+j]+mi[i+j][i+l]) {
							tot[i][i+l]+=tot[i][i+j]*tot[i+j][i+l];
						//	cout <<i <<" " <<i+j <<" " <<i+l <<" " <<tot[i][i+j] <<" " <<tot[i+j][i+l] <<"\n";
						}
					}
				}
			}
			for (int i=1;i<=n;i++) {
				for (int j=i+1;j<=n;j++) {
					if (tot[i][j]==2) ans++;
				}
			}
			cout <<ans <<"\n";
		} else if (c==11 || c==12) {
			bool f=1;
			if (x[2]-x[1]>=d) {
				f=0;
				cout <<"0\n";
			} else {
				for (int i=2;i<=n;i++) {
					if (x[i]-x[1]>d) {
						for (int j=i-1;j<=n;j++) {
							if (x[j]-x[i-1]>d) {
								f=0;
								cout <<n-(j-3) <<"\n";
								break;
							}
						}
						break;
					}
				}
			}
			if (f) cout <<"0\n";
		}
	}
	return 0;
}
/*

0 1
10 3
0 3 6 7 8 9 10 13 16 19

*/
