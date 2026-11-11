#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],ki,idx;
int g[1005][1005];
bool gg[505];
struct ww{
	int x,y,quan;
	bool operator < (const ww w2)const{
		return quan<w2.quan;
	}
};
ww w1[505];
int dfs(int x,int y){
	
	for(int i=1;i<=m;i++){
		if(g[x][i]!=0&&i==y) return g[x][i];
		if(g[x][i]!=0){
			g[x][y]=dfs(i,y)+g[x][i];
			break;
		}
	}
	return g[x][y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c>=7 && c<=11){
		for(int i=1;i<=n;i++){
			cin>>ki;
			int x1,x2,y1,y2;
			cin>>x1>>x2>>y1>>y2;
			if(w1[idx].quan!=0){
				idx++;
				w1[idx].x=x1;
				w1[idx].y=y1;
				w1[idx].quan=min(x2+y2,w1[idx].quan);
			}else{
				w1[idx].x=x1;
				w1[idx].y=y1;
				w1[idx].quan=x2+y2;
			}
		}
		sort(w1+1,w1+1+idx);
		gg[w1[1].x]==1;
		gg[w1[1].y]==1;
		g[w1[1].x][w1[1].y]=w1[1].quan;
		for(int i=2;i<=idx;i++){
			if(gg[w1[i].x]==0||gg[w1[i].y]==0){
				gg[w1[i].x]==1;
				gg[w1[i].y]==1;
				g[w1[i].x][w1[i].y]=w1[i].quan;
			}
		}
		for(int i=1;i<=q;i++){
			int xx,yy;
			cin>>xx>>yy;
			cout<<dfs(xx,yy);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			
		}
	}
	return 0;
}
