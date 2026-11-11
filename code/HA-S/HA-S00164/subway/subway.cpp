#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][500005],x,y;
vector<int> aa[500005];
void dfs(int x,int y,int nowz,int nowx){
	
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k[i];j++){
			aa[a[i][j]].push_back(a[i][j-1]);
			aa[a[i][j-1]].push_back(a[i][j]);
		}
	}
	while(q--){
		long long ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		for(int i=0;i<aa.size();i++){
			dfs(x,y,x,aa[i][]);
		}
		
		
		
	}
	return 0;
}
