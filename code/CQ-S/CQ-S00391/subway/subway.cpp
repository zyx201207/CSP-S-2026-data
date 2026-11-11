#include<bits/stdc++.h>
#define int long long 
using namespace std;
namespace FastIO{
	inline int_fast64_t Int_read(){
		int opt=1,cnt=0;
		static char c=getchar();
		while(!isdigit(c)){
			if(c=='-')opt=-1;
			c=getchar();
		}
		while(isdigit(c)){
			cnt=(cnt<<3)+(cnt<<1)+(c^48);
			c=getchar();
		}
		return opt*cnt;
	}
	template<class _t> inline void Int_write(const _t &n){
		if(n<0){
			putchar('-');
			Int_write(-n);
			return;
		}
		if(n>9)Int_write(n/10);
		putchar(n%10+48);
	}
}
using namespace FastIO;
int now,n,m,top,T,w[500010],k[510],f[510][510],vis[510];
vector<int> a[510];
vector<int> t[510];
vector<pair<int,int>> pos[500010];
vector<pair<int,int>> vec[510];
queue<int> q;
void solve(int x){
	for(int i=1;i<x;i++){
		f[x][i]=f[i][x];
	}
	memset(vis,0,sizeof vis);
	f[x][x]=0;vis[x]=1;q.push(x);
	while(!q.empty()){
		int y=q.front();
		q.pop();vis[y]=0;
		for(int i=0;i<vec[y].size();i++){
			int z=vec[y][i].first;
			int w=vec[y][i].second;
			if(f[x][z]>f[x][y]+w){
				f[x][z]=f[x][y]+w;
				if(!vis[z]){
					vis[z]=1;
					q.push(z);
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	now=FastIO::Int_read();
	n=FastIO::Int_read();
	m=FastIO::Int_read();
	top=FastIO::Int_read();
	T=FastIO::Int_read();
	for(int i=1;i<=m;i++){
		w[i]=FastIO::Int_read();
	}
	for(int i=1;i<=n;i++){
		k[i]=FastIO::Int_read();
		for(int j=1;j<=k[i];j++){
			int x,y;
			x=FastIO::Int_read();
			y=FastIO::Int_read();
			a[i].push_back(x);
			t[i].push_back(y);
			pos[x].push_back({i,j-1});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<pos[i].size();j++){
			for(int k=j+1;k<pos[i].size();k++){
				int y=pos[i][j].first;
				int z=pos[i][k].first;
				int cnt=t[y][pos[i][j].second]+t[z][pos[i][k].second];
				vec[y].push_back({z,cnt});
				vec[z].push_back({y,cnt});
			}
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		solve(i);
	}
	while(T--){
		int x,y,ans=LONG_LONG_MAX;
		cin >> x >> y;
		for(int i=0;i<pos[x].size();i++){
			if(t[pos[x][i].first][pos[x][i].second]>=ans)continue;
			for(int j=0;j<pos[y].size();j++){
				int l=pos[x][i].first;
				int r=pos[y][j].first;
				int cnt=t[l][pos[x][i].second]+t[r][pos[y][j].second]+f[l][r];
				ans=min(ans,cnt);
			}
		}
		FastIO::Int_write(ans+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}
