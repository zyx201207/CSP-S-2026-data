#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long

ll t[500010][20];
int si[500010],l[500010][20];
int w[500010];

ll f[510][510];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		int k;cin>>k;
		while(k--){
			int u,val;cin>>u>>val;
			t[u][si[u]]=val,l[u][si[u]]=i,si[u]++;
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=0;i<n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<si[i];j++)for(int k=0;k<si[i];k++){
			f[l[i][j]][l[i][k]]=min(f[l[i][j]][l[i][k]],t[i][j]+t[i][k]);
			f[l[i][k]][l[i][j]]=min(f[l[i][k]][l[i][j]],t[i][j]+t[i][k]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++)f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		ll mi=1e18;
		for(int i=0;i<si[u];i++)for(int j=0;j<si[v];j++){
			mi=min(mi,t[u][i]+f[l[u][i]][l[v][j]]+t[v][j]);
		}
		cout<<mi+w[u]+w[v]<<"\n";
	}
}
// 15:21
