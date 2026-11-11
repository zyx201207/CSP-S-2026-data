#include<bits/stdc++.h>
const int N=15e2+10;
using namespace std;
int c,n,m,d,q,l[N][N],w[N],k,a,t;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			if(i!=j){
				l[i][j]=1e9;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			l[a+n][i]=l[i][a+n]=t;
		}
	}
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<l[x+n][y+n]+w[x]+w[y]<<endl;
	}
	return 0;
}
