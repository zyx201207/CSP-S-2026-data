#include<bits/stdc++.h>
using namespace std;
int n,ccc,m,d,q,lz[505],cd;//路线 
bool book[505];
int w[500005];//入口到站厅时间 
int a[505][25],b[505][25],cx[505][505],a1[505];
struct kkk{
	int a,t;
}k[505][200005];
struct cc{
	int x,y;
}r[100005];//计划 
int dfs(int xx,int c,int top){
	if(top==xx){
		cd=min(c-1,cd);
		return 0;
	}
	for(int i=1;i<=a1[top];i++){
		if(book[a[top][i]]==false){
			book[a[top][i]]=true;
			lz[c]=a[top][i];
			int f=dfs(xx,c+1,a[top][i]);
			book[a[top][i]]=false;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>k[i][j].a>>k[i][j].t;
			int u=k[i][j].a,v=k[i][j-1].a;
			a1[u]++;
			a1[v]++;
			a[u][a1[u]]=v;//线路 
			a[v][a1[v]]=u;
			b[u][i]=k[i][j].t;//站厅到站台时间 
			b[v][i]=k[i][j-1].t;
			cx[v][u]=i;
			cx[u][v]=i;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].x>>r[i].y;
	}
	int s=1;
	while(s<=q){
		long long cnt;
		for(int i=1;i<=500;i++) {
			book[i]=false;
			lz[i]=0;
		}
		lz[1]=r[s].x;
		book[r[s].x]=true;
		dfs(r[s].y,2,r[s].x);
		cnt+=w[r[s].x]+w[r[s].y];
		for(int i=1;i<=cd-1;i++){
			cnt+=b[lz[i]][cx[lz[i]][lz[i+1]]];
			cnt+=b[lz[i+1]][cx[lz[i]][lz[i+1]]];
		}
		cout<<cnt;
		s++;
	}
	return 0;
}
