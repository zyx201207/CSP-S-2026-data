#include<bits/stdc++.h>
#define tyui long long
#define florr(a,b,c) for(int a=(b);a<=(c);a++)
#define deflo(a,b,c) for(int a=(b);a>=(c);a--)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define AC_AK flush(),exit(0);
#define eb emplace_back
using namespace std;
namespace Rukia{
	static const int Buf1=1<<24,Buf2=1<<22;
	static char bufr[Buf1],bufw[Buf2],*hand=bufr,*bottom=bufr,*wp=bufw;
	inline char gc(){
		if(hand==bottom){
			bottom=bufr+fread(bufr,1,Buf1,stdin),hand=bufr;
			if(hand==bottom) return 0;
		}
		return *hand++;
	}
	inline void pc(char c){
		if(wp==bufw+sizeof(bufw)) fwrite(bufw,1,sizeof(bufw),stdout),wp=bufw;
		*wp++=c;
		return;
	}
	inline void flush(){
		fwrite(bufw,1,wp-bufw,stdout),wp=bufw;
		return;
	}
	inline int in(){
		char c=gc();
		int f=1,k=0;
		for(;!isdigit(c);c=gc()) f=(c=='-')?-1:1;
		for(;isdigit(c);c=gc()) k=10*k+c-'0';
		return k*f;
	}
	void out(tyui x){
		if(x<0) pc('-');
		if(x<10) pc(x+'0');
		else out(x/10),pc(x%10+'0');
		return;
	}
}
using namespace Rukia;
const int N=510,M=5e5+10;
struct Miyamizu{
	int cnt,head[N];
	struct Mitsuha{
		int w,to,nxt;
	}e[N*N];
	void add(int u,int v,int w){
		e[++cnt].w=w,e[cnt].to=v,e[cnt].nxt=head[u],head[u]=cnt;
	}
}gr;
int c,n,m,d,q,x,y,w[M],k[N];
tyui dist[N][N];
vector<int> a[N],t[N];
vector<pair<int,int> > inwh[M];
/*
 * c:测试点编号
 * n:地铁线路数
 * m:地铁站数
 * d:每个地铁站最多被几条线路经过
 * q:出行计划数 1e5
 * w[i]:表示从每个地铁站的地铁口走到站厅需要的时间
 * k[i]:表示第 i 条线路经过的地铁站数
 * a[i][j]:表示第 i 条线路经过的第 j 个地铁站
 * t[i][j]:表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
*/
inline void slv(){
	x=in(),y=in();
	tyui ans=w[x]+w[y],hj=LLONG_MAX>>1;
	for(int i=0;i<(int)inwh[x].size();i++)
		for(int j=0;j<(int)inwh[y].size();j++){
			pair<int,int> xz=inwh[x][i],yz=inwh[y][j];
			hj=min(hj,t[xz.first][xz.second]+t[yz.first][yz.second]+dist[xz.first][yz.first]);
		}
	out(ans+hj),pc('\n');
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in(),n=in(),m=in(),d=in(),q=in();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dist[i][j]=LLONG_MAX>>1;
	for(int i=1;i<=m;i++) w[i]=in();
	for(int i=1;i<=n;i++){
		k[i]=in();
		a[i].eb(0),t[i].eb(0);
		for(int j=1;j<=k[i];j++){
			a[i].eb(in()),t[i].eb(in()),inwh[a[i][j]].eb(make_pair(i,j));
			for(int ui=0;ui<(int)inwh[a[i][j]].size()-1;ui++){
				pair<int,int> yuh=inwh[a[i][j]][ui];
				dist[yuh.first][i]=dist[i][yuh.first]=min(dist[i][yuh.first],t[i][j]+t[yuh.first][yuh.second]);
			}
		}
	}
	while(1){
		bool fl=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				for(int cv=1;cv<=n;cv++){
					if(dist[i][j]>dist[i][cv]+dist[cv][j]) dist[i][j]=dist[i][cv]+dist[cv][j],fl=0;
				}
			}
		}
		if(fl) break;
	}
	while(q--) slv();
	AC_AK
}
/*
 * 15:19
 * 注意要往返
 * 需要log做法
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
* easy
* wait
* ???全源最短路怎么打
* 完了
 */
