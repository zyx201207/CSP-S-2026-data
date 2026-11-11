#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[1010];
int t[510][1010];
int a[510][1010];
int to[1010][1010];
int k[510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(t,-0x3f3f3f3f3f3f3f3f,sizeof(t));
	memset(to,0x3f3f3f3f3f3f3f3f,sizeof(to));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				if(to[a[i][j]][a[i][l]]>t[i][j]+t[i][l]){
					to[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
				}
			}
		}
	}
	for(int i=1;i<=1010;i++){
		to[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int l=i;l<=j;l++){
				to[i][j]=min(min(to[i][l],to[l][i])+min(to[j][l],to[l][j]),min(to[j][i],to[i][j]));
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<min(to[x][y],to[y][x])+w[x]+w[y]<<"\n";
	}
	return 0;
}
