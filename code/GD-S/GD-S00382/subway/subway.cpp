#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[7000],a[7000],k,t[7000],to[7000][7000];
bool book[7000][7000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	memset(to,0x3f,sizeof(to));
	for(int i=1; i<=n; i++) {
		cin>>k;
		for(int j=1; j<=k; j++)
			cin>>a[j]>>t[j];
		for(int j=1; j<=k; j++) {
			for(int u=j+1; u<=k; u++) {
				if(j==u)continue;
				if(!book[to[a[j]][a[u]]]){
					to[a[j]][a[u]]=t[j]+t[u];
					to[a[u]][a[j]]=t[j]+t[u];
				}else if(t[j]+t[u]<to[a[j]][a[u]]){
					to[a[j]][a[u]]=t[j]+t[u];
					to[a[u]][a[j]]=t[j]+t[u];
				}
				book[a[j]][a[u]]=1;
				book[a[u]][a[j]]=1;
			}
		}
	}
	for(int k=1; k<=m; k++)
		for(int i=1; i<=m; i++)
			for(int j=1; j<=m; j++) {
				if(!book[i][k]||!book[k][j])continue;
				if(!book[i][j]){
					book[i][j]=1;
					to[i][j]=to[i][k]+to[k][j];
				}else if(to[i][k]+to[k][j]<to[i][j])to[i][j]=to[i][k]+to[k][j];
			}

	while(q--) {
		long long x,y;
		cin>>x>>y;
		cout<<to[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
