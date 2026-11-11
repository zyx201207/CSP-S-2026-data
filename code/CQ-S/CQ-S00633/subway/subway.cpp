#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,a[505][505],b[505][505],s[505][505],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>a[i][j]>>b[i][a[i][j]];
			s[a[i][j]][a[i][j-1]]=i;
			s[a[i][j-1]][a[i][j]]=i;
		}
	}for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(s[x][y]!=0){
			cout<<w[x]+w[y]+b[s[x][y]][x]+b[s[x][y]][y]<<"\n";
			continue;
		}for(int j=1;j<=m;j++){
			if(s[x][j]!=0&&s[y][j]!=0){
				cout<<w[x]+w[y]+b[s[x][j]][x]+b[s[x][j]][j]+b[s[y][j]][j]+b[s[y][j]][y]<<"\n";
				break;
			}
		}
	}return 0;
} 
