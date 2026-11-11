#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int mp[N*2][N*2],w[N];
vector<int>a[N*2],t[N*2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m*2;i++){
		for(int j=1;j<=m*2;j++){
			mp[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a[i].resize(k+1000);
		t[i].resize(k+1000);
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]][a[i][j]+m]=t[i][j];
			mp[a[i][j]+m][a[i][j]]=t[i][j];
		}
		for(int j=2;j<=k;j++){
			//cout<<a[i][j]<<' '<<a[i][j-1]<<endl;
			mp[a[i][j-1]][a[i][j]]=0;
			mp[a[i][j]][a[i][j-1]]=0;
		}
	}
	for(int k=1;k<=m*2;k++){
		for(int i=1;i<=m*2;i++){
			for(int j=1;j<=m*2;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<mp[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
