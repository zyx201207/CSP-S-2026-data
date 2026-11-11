#include<bits/stdc++.h>
using namespace std;
int n,m,q,c,h;
long long d[100005][100005];
int w[100005],a[505][100005],t[505][100005],k[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>h>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			d[i][j]=1000000001;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i]-1;j++){
			d[a[i][j]][a[i][j+1]]=0;
			d[a[i][j+1]][a[i][j]]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int g=1;g<=n-1;g++){
				d[a[g][j]][a[g+1][j]]=t[g][j]+t[g+1][j];
				d[a[g+1][j]][a[g][j]]=t[g][j]+t[g+1][j];
			}
		}
	}
	for(int g=1;g<=m;g++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				d[i][j]=min(d[i][j],d[i][g]+d[g][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int f=d[x][y]+w[x]+w[y];
		cout<<f<<endl;
	}
	return 0;
} 
