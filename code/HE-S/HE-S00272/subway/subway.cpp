#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10010],k[1010],a[1010][2010],t[1010][2010],p[1010][1010],vis[1010],x,y,o;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			for(int h=1;h<j;h++){
				p[a[i][h]][a[i][j]]=t[i][j]+t[i][h];
				o=t[i][h];
				p[a[i][j]][a[i][h]]=t[i][j]+t[i][h];
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+o*n<<"\n";
	}
	return 0;
}
