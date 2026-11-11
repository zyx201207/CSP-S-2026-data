#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r,x) for(int i=(l);i<=(r);i+=(x))
#define per(i,r,l,x) for(int i=(r);i>=(l);i-=(x))
#define pb push_back
#define pr pair<int,int>
#define fr first
#define sc second
using namespace std;
const int N=5e5+5,M=505,INF=1e18;
int c,n,m,d,q;
int w[N],len[N],dis[M][M],lastdis[M][M],DIS[N];
bool flag[N];
vector<int> id[N];
vector<pr> xwx[N];
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int erfen(int v,int x){
	int l=0,r=len[v]-1,res=len[v];
	while(l<=r){
		int mid=l+r>>1;
		if(xwx[v][mid].fr>=x)res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
void DIJ(int s){
	priority_queue<pr,vector<pr>,greater<pr>> q;
	memset(DIS,0x3f,sizeof(DIS));
	memset(flag,0,sizeof(flag));
	DIS[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().sc;
		q.pop();
		if(flag[u])continue;
		flag[u]=1;
		rep(v,1,n,1){
			if(u==v||dis[u][v]>=INF)continue;
			int w=dis[u][v];
			if(DIS[v]>DIS[u]+w){
				DIS[v]=DIS[u]+w;
				q.push({DIS[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	rep(i,1,m,1)w[i]=read();
	rep(i,1,n,1){
		len[i]=read();
		rep(j,1,len[i],1){
			int tmpa,tmpt;
			tmpa=read(),tmpt=read();
			xwx[i].pb({tmpa,tmpt});
			id[tmpa].pb(i);
		}
		sort(xwx[i].begin(),xwx[i].end());
	}
	memset(dis,0x3f,sizeof(dis));
	rep(i,1,n,1){
		rep(j,i+1,n,1){
			int u=i,v=j;
			if(len[u]>len[v])swap(u,v);
			for(auto k:xwx[u]){
				int x=k.fr,valx=k.sc;
				int w=erfen(v,x);
				if(w>=len[v])continue;
				int y=xwx[v][w].fr,valy=xwx[v][w].sc;
				if(x!=y)continue;
				dis[u][v]=dis[v][u]=min(dis[u][v],valx+valy);
			}
		}
	}
	memset(lastdis,0x3f,sizeof(lastdis));
	rep(i,1,n,1){
		DIJ(i);
		rep(j,1,n,1){
			lastdis[i][j]=min(lastdis[i][j],DIS[j]);
		}
	}
	while(q--){
		int x,y;
		x=read(),y=read();
		int ans=w[x]+w[y],minn=INF;
		for(auto u:id[x]){
			for(auto v:id[y]){
				int w1=erfen(u,x);
				int w2=erfen(v,y);
				minn=min(minn,lastdis[u][v]+xwx[u][w1].sc+xwx[v][w2].sc);
			}
		}
		write(ans+minn);
		puts("");
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

fc subway3.ans T2.txt /W
*/
