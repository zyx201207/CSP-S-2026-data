#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int tu[500050][500050];
int hed[500050];
int stopn[500050];
int train[500050];
void add(int u,int v){
	tu[train[u]][train[v]]=min(tu[train[u]][train[v]],train[u+1]+train[v+1]);
	tu[train[v]][train[u]]=min(tu[train[v]][train[u]],train[u+1]+train[v+1]);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(tu,0x3f,sizeof tu);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>stopn[i];
		stopn[i]*=2;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		k*=2;
		for(int j=1;j<=k;j++){
			cin>>train[j];
		}
		for(int j=1;j<=k;j+=2){
			for(int l=j+2;l<=k;l+=2){
				add(j,l);
//				cout<<train[j]<<' '<<train[l]<<' '<<tu[train[j]][train[l]]<<endl;
			}
		}
	}
//	cout<<tu[1][2]<<' '<<tu[2][3]<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				tu[i][j]=min(tu[i][k]+tu[k][j],tu[i][j]);
			}
		}
	}
//	cout<<tu[1][3]<<endl;
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		cout<<(tu[u][v]+stopn[u]/2+stopn[v]/2)%0x3f3f3f3f3f3f3f3f<<endl;
	}
}
