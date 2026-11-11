#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,x,y,z) for(int i=x;i<=y;i+=z)
#define REP(i,x,y,z) for(int i=x;i>=y;i-=z)
void rd(int &x){
	int f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	x*=f;
}void wr(int x,char end='\n'){
	if(x<0)putchar('-'),x=-x;
	int len=0,s[20];
	if(x==0)s[++len]=0;
	while(x)s[++len]=x%10,x/=10;
	while(len)putchar(s[len--]+'0');
	putchar(end);
}const int N=5e5+10;
int n,m,id,a[N],ans[N],cnt[N];
bool p[N],vis[N];
map<int,int>mp;vector<int>e[N];
void dfs(int u){
	if(vis[u])return;
	vis[u]=true;
	for(auto y:e[u]){
		if(vis[y])continue;
		dfs(y);cnt[u]+=cnt[y];
	}
}signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	rd(n),rd(m);FOR(i,1,n,1)rd(a[i]);
	REP(i,n,1,1)if(p[a[i]]==0)p[a[i]]=true,e[a[i+1]].push_back(a[i]);
	FOR(i,1,n,1)cnt[a[i]]++;
	dfs(0);FOR(i,1,m,1)wr(cnt[i],' ');
	return 0;
}
