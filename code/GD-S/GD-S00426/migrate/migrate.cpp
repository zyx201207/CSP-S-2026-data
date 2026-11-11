#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> inline void read(T &x){
	T w=1;
	x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const int N=2e6+10;
vector<int>v[N],g[N];
int n,m,id[N];
ll s[N][2];
int fa[N][2];
bool rt[N][2];
ll d,a[N];
//map<int,bool>mp[N];
//void sub1(){
//	ll ans=0;
//	for(int i=1;i<=n;++i){
//		for(int j=i+1;j<=n;++j){
//			if(id[i]!=id[j]) break;
//			int now=i;
//			ll sum1=0,sum2=0;
//			while(now<j){
//				if(now!=i) sum1+=now;
//				now=nxt[now];
//			}
//			now=j;
//			while(now>i){
//				if(now!=j) sum2+=now;
//				now=lst[now];
//			}
//			if(sum1-sum2==1) ++ans;
//		}
//	}
//	write(ans),putchar('\n');
//}
void dfs1(int u){// query for the second tree's sum 
	for(int p : v[u]){
		if(fa[u][1]==p) s[p][1]+=s[u][1]+g[p].size()-1;
		else s[p][1]+=g[p].size();
		dfs1(p);
	}
}
void dfs2(int u){// query for the first tree's sum 
	for(int p : g[u]){
		if(fa[u][0]==p) s[p][0]+=s[u][0]+v[p].size()-1;
		else s[p][0]+=v[p].size();
		dfs2(p);
	}
}
void solve(){
	read(n),read(d);
	for(int i=1;i<=n;++i){
//		nxt[i]=lst[i]=0;
		rt[i][0]=rt[i][1]=0;
		fa[i][0]=fa[i][1]=0;
		s[i][0]=s[i][1]=1;
		id[i]=0;
		v[i].clear(),g[i].clear();
	}
	int cnt=1;
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1,j=1;i<=n;++i){
		j=max(i,j);
		while(j<n&&a[j+1]-a[i]<=d) ++j;
		fa[i][0]=j;
		if(j!=i) v[j].emplace_back(i);
		id[i]=cnt;
		if(fa[i][0]==i) ++cnt,rt[i][0]=1;
//		cerr<<id[i]<<" ";
	}
	for(int i=n,j=n;i>=1;--i){
		j=min(i,j);
		while(j>1&&a[i]-a[j-1]<=d) --j;
		fa[i][1]=j;
		if(j!=i) g[j].emplace_back(i);
		if(fa[i][1]==i) rt[i][1]=1;
	}
	for(int i=1;i<=n;++i){
		if(rt[i][0]) s[i][1]+=g[i].size(),dfs1(i);
	}
	for(int i=1;i<=n;++i){
		if(rt[i][1]) s[i][0]+=v[i].size(),dfs2(i);
	}
	ll ans=0;
	for(int i=2;i<=n;++i){
//		cerr<<ans<<" ";
		if(id[i]!=id[i-1]) continue;
		if(rt[i][0]||rt[i-1][1]) continue;
		ll sum1=(fa[fa[i-1][1]][0]==i ? s[fa[i-1][1]][0]+v[i].size()-1 : v[i].size());
		sum1-=(fa[i-1][0]==i);
		ll sum2=(fa[fa[i][0]][1]==i-1 ? s[fa[i][0]][1]+g[i-1].size()-1 : g[i-1].size());
		sum2-=(fa[i][1]==i-1);
		ans+=sum1*sum2;
	}
	write(ans),putchar('\n');
//	for(int i=1;i<=n;++i) cerr<<fa[i][0]<<" ";
//	cerr<<"\n";
//	for(int i=1;i<=n;++i) cerr<<fa[i][1]<<" ";
//	cerr<<"\n";
//	for(int i=1;i<=n;++i) cerr<<s[i][0]<<" ";
//	cerr<<"\n";
//	for(int i=1;i<=n;++i) cerr<<s[i][1]<<" ";
//	cerr<<"\n";
	
}
int main(){
//	cerr<<fabs(&b1-&b2)/1048576.0<<"MB\n";
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid,T;
	read(cid),read(T);
	while(T--) solve();
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2

0 1
10 3
0 3 6 7 8 9 10 13 16 19

0
*/

