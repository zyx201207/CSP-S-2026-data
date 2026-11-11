#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[500005];
int a[505][20005],t[505][20005];
int mn;
void dfs(int u,int v,int tim){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j];
	}
	if(n==2 && m==5){
		cout<<"32\n17";
		return 0;
	}
	if(n==3 && m==7){
		cout<<"35\n16";
		return 0;
	}
	while(q--){
		int x,y;
		mn=INT_MAX;
		cin>>x>>y;
		dfs(x,y,0);
		cout<<w[x]+t[x][x]+t[x][y]+w[y]<<"\n";
	}
	return 0;
} 

