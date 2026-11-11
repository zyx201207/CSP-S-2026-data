#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t[500005][500005],w[500005],c,n,m,d,q,f,qu,qn,vis[500005][500005];
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct Fu{
	int x,y,cnt;
};
queue<Fu>o;
void bfs(){
	if(o.front().x==qn||o.front().y==qn){
		return;
	}for(int i=0;i<4;i++){
		int cx=o.front().x+dx[i];
		int cy=o.front().y+dy[i];
		if(cx>=qu&&cx<=qn&&cy>=qu&&cy<=qn&&t[cx][cy]!=0&&vis[cx][cy]!=1){
			vis[cx][cy]=1;
			o.push({cx,cy,o.front().cnt+t[cx][cy]});
			o.pop(); 
			bfs();
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int a,v;
		cin>>a;
		for(int j=1;j<=a;j++){
			int u,y;
			cin>>u>>y;
			if(j==1)v=u;
			t[u][v]=y;
			v=u;
		}
	}while(q--){
		cin>>qu>>qn;
		o.push({qu,qu,t[qu][qu]});
		vis[qu][qu]=1;
		bfs();
		int s;
		while(!o.empty()){
			s=o.front().cnt;
			o.pop();
		}
		cout<<s+w[qu]+w[qn]<<endl;
 		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				vis[i][j]=0;
			}
		}
	}
	return 0;
} 
