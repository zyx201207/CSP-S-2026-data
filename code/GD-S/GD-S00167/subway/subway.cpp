#include<bits/stdc++.h>
#include<windows.h>
#define ll long long
const int N=510,M=5e5+10;
//注意到可以分层图
//对于同一层内的点无贡献
//只有在切换层级时加入两个点的贡献
//点数<=1e5，但是每个点只占用20个以下的线路
//SCC？！
//建边开虚点 
//最终dij规模会被压到500，N*N*logN可过 
//有个问题："依次经过"貌似不能将地铁线路内当成SCC
//这个不对，不然样例1的(4,5)就违反规则了 

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+'0');
	return ;
}
 

int c,n,m,d,q,cnt=0;
int w[M];
std::vector<std::pair<int,int>> sg[M];
ll g[N][N];
int t[M][N];

inline void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=std::min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}	
}

inline void solve(){
	memset(g,0x3f,sizeof g);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		g[i][i]=0;
		int ki;
		ki=read();
		for(int j=1;j<=ki;j++){
			int x,y;
			x=read(),y=read();
			sg[x].push_back({i,y});
			t[i][x]=y;
		}
	}
	//建图 
	for(int i=1;i<=m;i++){//节点  
		for(int j=0;j<sg[i].size();j++){
			for(int k=j+1;k<sg[i].size();k++){
				g[sg[i][j].first][sg[i][k].first]=
				g[sg[i][k].first][sg[i][j].first]=
				std::min(g[sg[i][j].first][sg[i][k].first],(ll)sg[i][j].second+(ll)sg[i][k].second);
			}
		}
	}
	Floyd();
	while(q--){
		int x,y;
		x=read(),y=read();
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto &p:sg[x]){
			for(auto &q:sg[y]){
				ans=std::min(ans,g[p.first][q.first]+(ll)t[p.first][x]+(ll)t[q.first][y]);
			}
		}
		ans+=(ll)w[x]+(ll)w[y];
		print(ans);
		printf("\n");
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
