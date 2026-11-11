#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[510];
int a[510][5000];
int t[510][5000];
int k[510];
int x[100010],y[100010];
int vis[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){
		
		cout<<w[x[i]]+t[x[i]][x[i]]+t[x[i]][y[i]]+w[y[i]]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
