#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010],k[510];
int p[510][100][2];
int dfs(int s,int e,int t){
	if(s==e){
		return t;
	}
	for(int i=s;i<=p[s][i][1];){
		dfs(i,e,t+p[s][i][2]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			p[i][j][1]=a;
			p[i][j][2]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,y,0);
	}
	return 0;
}
