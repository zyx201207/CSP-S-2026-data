#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],pd[500010][25][2],gs[500010],head[505],cnt,ans[505][505],bjzg[505],vis[505];
struct florr{
	int dis;
	int to;
	int next;
}e[5000010];

void add(int x,int y,int z){
	cnt++;
	e[cnt].dis=z;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}

priority_queue <pair<int,int>> dj;

void djizdl(int qd){
	dj.push(make_pair(qd,0));
	ans[qd][qd]=0;
	while(!dj.empty()){
		int pos=dj.top().first;
		int dis=dj.top().second;
		dj.pop();
		if (vis[pos]) continue;
		vis[pos]=1;
		for (int i=head[pos];i;i=e[i].next){
			int wzz=e[i].to;
			if (ans[qd][wzz]>dis+e[i].dis){
				ans[qd][wzz]=dis+e[i].dis;
				if (!vis[wzz]){
					dj.push(make_pair(wzz,ans[qd][wzz]));
				}
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) ans[i][j]=99999999;
	}
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		int gs1;
		cin>>gs1;
		for (int j=1;j<=gs1;j++){
			int zt,sj;
			cin>>zt>>sj;
			gs[zt]++;
			pd[zt][gs[zt]][0]=i;
			pd[zt][gs[zt]][1]=sj;
			if (gs[zt]>=2){
				for (int zh=1;zh<gs[zt];zh++){
					add(i,pd[zt][zh][0],sj+pd[zt][zh][1]);
					add(pd[zt][zh][0],i,sj+pd[zt][zh][1]);
				}
			}
		}
	}
	
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++) vis[j]=0;
//		djizdl(i);
//	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++){
//			cout<<ans[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	for (int i=1;i<=q;i++){
		int posx,posy,ans1=99999999;
		cin>>posx>>posy;
		for (int xx=1;xx<=gs[posx];xx++){
			for (int yy=1;yy<=gs[posy];yy++){
				if (bjzg[pd[posx][xx][0]]) ans1=min(ans1,ans[pd[posx][xx][0]][pd[posy][yy][0]]+pd[posx][xx][1]+pd[posy][yy][1]+w[posx]+w[posy]);
				else{
					if (bjzg[pd[posy][yy][0]]) ans1=min(ans1,ans[pd[posy][yy][0]][pd[posx][xx][0]]+pd[posx][xx][1]+pd[posy][yy][1]+w[posx]+w[posy]);
					else{
						for (int i=1;i<=n;i++) vis[i]=0;
						djizdl(pd[posx][xx][0]);
						bjzg[pd[posx][xx][0]]=1;
//						cout<<ans[pd[posx][xx][0]][pd[posy][yy][0]]<<" "<<pd[posx][xx][1]<<" "<<pd[posy][yy][1]<<" "<<w[posx]<<" "<<w[posy]<<endl;
						ans1=min(ans1,ans[pd[posx][xx][0]][pd[posy][yy][0]]+pd[posx][xx][1]+pd[posy][yy][1]+w[posx]+w[posy]);
					}
				}
			}
		}
		cout<<ans1<<endl;
	}
	return 0;
}

