#include<bits/stdc++.h>
#define N 1005
#define ll long long
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
ll n,m,k,jk,ans,sum,num,cnt,tot;
ll head[N],dis[N],vis[N],wis[N][N],f[N][N];
vector<ll> G[N];

void read(ll &x){
	x=0;ll ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(ll x){
	if(x<0){x=-x;putchar('-');}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));return;
}

void F(ll x,ll y){
	if(!vis[x]) return;
	head[x]=1;
	for(auto v:G[x]){
		if(v==y) continue;
		F(v,x);
	}return;
}

ll Get(){
	for(ll i=1;i<=n;i++) head[i]=0;
	ll z=0;
	for(ll i=1;i<=n;i++) if(!head[i]&&vis[i]) F(i,0),z++;
	if(z>2) return 1e15;
	ll zz=0;
//	for(int i=1;i<=n;i++) wk(vis[i]);
//	puts("");
	for(ll i=1;i<=n;i++){z=1e15;
		if(vis[i]) continue;
		for(ll j=1;j<=n;j++){
			if(!vis[j]) continue;
			z=min(z,wis[i][j]);
		}zz=max(zz,z);
	}return zz;
}

void dfs(ll x,ll y){
	if(y>=m||x>n){
		if(y!=m) return;
		ans=min(ans,Get());
		return;
	}
	vis[x]=1,dfs(x+1,y+1);
	vis[x]=0,dfs(x+1,y);
}

void solve(ll x,ll y,ll z){
	if(x!=z) wis[z][x]=wis[z][y]+1;
	for(auto v:G[x]){
		if(v==y) continue;
		solve(v,x,z);
	}return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(jk);read(jk);while(jk--){
		read(n),read(m);
		for(ll i=1;i<=n;i++) G[i].clear();
		for(ll i=1,x,y;i<n;i++){
			read(x),read(y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		for(ll i=1;i<=n;i++) wis[i][i]=0,solve(i,0,i);
		ans=1e15;dfs(1,0);wh(ans);
	}
	return 0;
}/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
