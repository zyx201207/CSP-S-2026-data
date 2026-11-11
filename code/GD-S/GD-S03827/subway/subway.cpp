#include<iostream>
#include<cstring>
//#define int long long
using namespace std;

long long c,n,m,d,q;
int w[500010];
long long t[500010][21];
int line[500010][21];
long long f[510][510];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		for(int j=1;j<=k;++j){
			int x,y;cin>>x>>y;
			t[x][i]=y;
			line[x][++line[x][0]]=i;
		}
	}
	memset(f,63,sizeof(f));
	for(int i=1;i<=m;++i){
		for(int j=1;j<=line[i][0];++j){
			int x=line[i][j];
			for(int k=j+1;k<=line[i][0];++k){
				int y=line[i][k];
//				cout<<i<<" "<<x<<" "<<y<<endl;
				f[x][y]=f[y][x]=min(f[x][y],t[i][x]+t[i][y]);
			}
		}
	}
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			if(f[i][k]>4e18)continue;
			for(int j=i+1;j<=n;++j){
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[j][k]); 
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;++i){
		int x,y;cin>>x>>y;
		long long s=9e18;
		for(int j=1;j<=line[x][0];++j){
			int l=line[x][j];
			for(int k=1;k<=line[y][0];++k){
				int r=line[y][k];
//				cout<<l<<" "<<r<<" "<<f[l][r]<<" "<<t[x][j]<<" "<<t[y][k]<<endl;
				s=min(s,f[l][r]+t[x][l]+t[y][r]);
			}
		}
		cout<<s+w[x]+w[y]<<endl;
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
