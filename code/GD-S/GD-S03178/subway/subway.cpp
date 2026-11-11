#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int INF = 1000000000;
int n,m,d,q,c,k,t,x,y;
int w[MAXN],a[MAXN];
int mp[MAXN][MAXN];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m*(n+1);i++){
		for(int j=1;j<=m*(n+1);j++){
			if(i==j)continue;
			mp[i][j]=INF;
		}
	}
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a[j]>>t;
			mp[a[j]][a[j]+i*m]=t;
			mp[a[j]+i*m][a[j]]=t;
			for(int tt=1; tt<j; tt++) {
				mp[a[tt]+i*m][a[j]+i*m]=0;
				mp[a[j]+i*m][a[tt]+i*m]=0;
			}
		}
	}
	for(int k=1; k<=m*(n+1); k++) {
		for(int i=1; i<=m*(n+1); i++) {
			for(int j=1; j<=m*(n+1); j++) {
				mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
			}
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>x>>y;
		cout<<mp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
