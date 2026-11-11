#include<bits/stdc++.h>
using namespace std;
struct point{
	long long to,w;
};
int c,n,m,d,q;
long long ans;
long long ti[500005],t[500505];
long long tim[505][505];
vector<point> s[500505];
void bfs(int u){
	queue<int> q;
	q.push(u);
	memset(t,0x3f,sizeof(t));
	t[u]=0;
	while(!q.empty()){
		long long x=q.front();
		q.pop();
		int len=s[x].size();
		for(int i=0;i<len;i++){
			int tx=s[x][i].to;
			long long w=s[x][i].w;
			if(t[x]+w<t[tx]){
				t[tx]=t[x]+w;
				q.push(tx);
			}
		}
	}
}
long long read(){
	char c;
	long long s=0,t=1;
	c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') t=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') s=s*10+c-'0',c=getchar();
	return s*t;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) ti[i]=read();
	for(int i=1;i<=n;i++){
		long long k;
		k=read();
		for(int j=1;j<=k;j++){
			long long x,y;
			x=read(),y=read();
			s[i+m].push_back({x,y});
			s[x].push_back({i+m,y});
		}
	}
	for(int i=1;i<=n;i++){
		bfs(m+i);
		for(int j=1;j<=n;j++) tim[i][j]=t[m+j];
	}
	while(q--){
		long long x,y;
		ans=1e18;
		x=read(),y=read();
		int len1=s[x].size();
		int len2=s[y].size();
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				long long we=tim[s[x][i].to-m][s[y][j].to-m]+s[x][i].w+s[y][j].w;
				if(we<ans) ans=we;
			}
		}
		printf("%lld\n",ans+ti[x]+ti[y]);
	}
}
