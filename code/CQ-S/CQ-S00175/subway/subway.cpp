#include <bits/stdc++.h>
#define int long long
#define N 510
#define M 40010
#define Q 100010
#define inf (int)1e18
#define debug(x) cout<<#x<<" = "<<x<<' '
using namespace std;

struct Subway{
	int tot;
	vector<int> vis;
};

struct Edge{
	int l,r,nxt;
	vector<int> line;
}e[16*M];
int elast[N],Len=1; 
void add(int l,int r,int col){
	int ps=0;
	for(int i=elast[l];i;i=e[i].nxt){
		if(e[i].r == r){
			ps=i;
			break;
		}
	}
	
	if(ps == 0){
		e[Len].l=l,e[Len].r=r,e[Len].nxt=elast[l],e[Len].line.push_back(col);
		elast[l]=Len++;
	}else e[ps].line.push_back(col);
}

struct Node{
	int val,id,col;
};
bool operator <(Node a,Node b){
	return a.val > b.val;
}

struct Question{
	int st,ed,id;
}q[Q];
bool cmp(Question a,Question b){
	return a.st < b.st;
}

int c,n,m,d,T,lstme;
int w[M],ans[Q];
int lth1[N][M],lth2[M][N],vis[M][N],dis[M][N],pre[2][M][N];
Subway s[N];
priority_queue<Node> pq;

inline void init(){
	cin>>c>>n>>m>>d>>T;
	for(register int i=1;i<=m;i++) cin>>w[i];
	for(register int i=1;i<=n;i++){
		cin>>s[i].tot;
		for(register int j=1;j<=s[i].tot;j++){
			register int pos,tme;cin>>pos>>tme;
			s[i].vis.push_back(pos);
			lth1[i][pos]=lth2[pos][i]=tme;
		}
		
		for(register int j=1,Mx=s[i].vis.size();j<Mx;j++)
			add(s[i].vis[j-1],s[i].vis[j],i),add(s[i].vis[j],s[i].vis[j-1],i);
	}
	
	for(register int i=1;i<=T;i++) cin>>q[i].st>>q[i].ed,q[i].id=i;
	sort(q+1,q+T+1,cmp);
}

inline int Dis(int id,int col){
	if(pre[0][id][col] == lstme) return dis[id][col];
	return inf;
}
inline int Vis(int id,int col){
	if(pre[1][id][col] == lstme) return vis[id][col];
	return 0;
}
inline void Dijstra(int st){
	dis[st][0]=0,pre[0][st][0]=lstme;
	pq.push({0,st,0});
	
	while(!pq.empty()){
		register int id=pq.top().id,line=pq.top().col;pq.pop();
		if(Vis(id,line)) continue;
		vis[id][line]=1,pre[1][id][line]=lstme;
		
		for(register int i=elast[id];i;i=e[i].nxt){
			int r=e[i].r,w=0;
			for(register int j=0,Mx=e[i].line.size();j<Mx;j++){
				int col=e[i].line[j];
				if(col == line) w=Dis(id,line)-lth2[id][col];
				else w=Dis(id,line)+lth2[id][col];
				w+=lth1[col][r];
//				debug(id),debug(r),debug(col),debug(w),debug(line)<<endl;
				
				if(w < Dis(r,col))
					dis[r][col]=w,pre[0][r][col]=lstme,
					pq.push({w,r,col});
			}
		}
	}
}

inline void solve(int i){
	if(q[i].st != q[i-1].st) lstme=i,Dijstra(q[i].st);
	int res=inf;
	for(int col=1;col<=n;col++) res=min(res,Dis(q[i].ed,col));
	ans[q[i].id]=res+w[q[i].st]+w[q[i].ed];
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	init();
	for(register int i=1;i<=T;i++) solve(i);
	for(register int i=1;i<=T;i++) cout<<ans[i]<<"\n";
	return 0;
}
