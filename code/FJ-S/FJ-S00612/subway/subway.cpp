#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500000],k[500],x,y,ans;
int t[5000][5000],vis[500];
struct Node{
	int a,t;
}r1,r2;
vector<int> e[500];
int dfs(int start,int end){
	if(start==end){
		return 0;
	}
	int num=1e8;
	if(vis[start]==1){
		return 0;
	}
	vis[start]=1;
	for(int i=0;i<e[start].size();i++){
		num=min(num,t[start][e[start][i]]+t[e[start][i]][start]+dfs(e[start][i],end));
	}
	return num;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cin>>r1.a>>r1.t;
		for(int j=2;j<=k[i];j++){
			cin>>r2.a>>r2.t;
			e[r1.a].push_back(r2.a);
			e[r2.a].push_back(r1.a);
			t[r1.a][r2.a]=r1.t;
			t[r2.a][r1.a]=r2.t;
			swap(r1,r2);
		}
	}
	while(q--){
		cin>>x>>y;
		ans=dfs(x,y);
		/*bool ifx=0,ify=0;
		int ans=1e8,num=0;
		for(int i=1;i<=n;i++){
			ifx=0;
			ify=0;
			for(int j=1;j<=k[i];j++){
				if(s[i][j].a==x){
					ifx=1;
				}
				if(s[i][j].a==y){
					ify=1;
				}
			}
			if(ifx&&ify){
				if(x>y) swap(x,y);
				for(int j=x;j<=y;j++){
					num+=s[i][j].t;
				}
			}
			ans=min(ans,num);
		}*/
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
