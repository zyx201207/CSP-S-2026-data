#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,f,w[505],k[550005],a[505][505],t[505][505],x,y;
long long l;
bool b[500][500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			b[a[i][j-1]][a[i][j]]=i;
		}
	}
	while(q--){
		l=0;
		cin>>x>>y;	
		l+=w[x];
		l+=t[x][x];
		int i=x,j=x+1;
		while(j<y){
			l+=t[i][j];
			++i;
			l+=t[i][j];
			++j;
		}
		l+=t[y-1][y];
		l+=w[y];
		cout<<l<<"\n";
	}
	return 0;
}
