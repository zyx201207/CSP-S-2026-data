#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,r,w[500050],x[500050],y[500050];
int a[10000][10000],t[10000][10000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>a[i][1];
		for(int j=2;j<=a[i][1];j++){
			t[i][1]=a[i][1];
			cin>>a[i][j]>>t[i][j];
		}
	}for(int i=1;i<=r;i++){
		cin>>x[i]>>y[i];
		cout<<w[x[i]]+w[y[i]]+t[1][x[i]]+t[1][y[i]]<<'\n';
	}
	return 0;
} 
