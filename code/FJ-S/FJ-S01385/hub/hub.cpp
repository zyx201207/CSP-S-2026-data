#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
struct node{
	int next,to;
}e[N*2];
int head[N],pos=0;
inline void add(int u,int v){
	pos+=1;
	e[pos].next=head[u];
	e[pos].to=v;
	head[u]=pos;
	return;
} 
int c,q,n,k,a[N],cc[N];
inline void dfs(int u,int fa,int col){
	if(fa!=0) cc[u]=col+(a[u]!=a[fa]);
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u,cc[u]);
	}
	return;
}
int in[N],tong[N];
inline void solve(){
	cin >> n >> k;
	pos=0;
	for(int i=1;i<=n;i++) head[i]=0,in[i]=0;
	for(int i=1,x,y;i<=n-1;i++){
		cin >> x >> y;
		add(x,y),add(y,x);
		in[x]+=1;in[y]+=1;
	}
	int st=0;
	for(int i=1;i<=n;i++) if(in[i]==1) st=i;
	int ans=1e18;
	for(int u=0;u<(1<<n);u++){
		for(int i=1;i<=n;i++) cc[i]=0,tong[i]=1e18;
		int t=u,id=1,p=0;
		while(t){
			a[id]=t%2;
			if(t%2==1) p+=1;
			t/=2; id+=1;
		}
		if(p!=k) continue;
		dfs(st,0,1);
		int g=0,gg=0;
		bool f=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				if(!g) g=cc[i];
				else if(!gg) gg=cc[i];
				else f=1;
			}
		}
		//if(f) continue;
		for(int i=1;i<=n;i++){
			if(cc[i]==g||cc[i]==gg) tong[cc[i]]=1e18;
			else if(tong[cc[i]]==1e18) tong[cc[i]]=1;
			else tong[cc[i]]+=1;
		}
//		for(int i=1;i<=n;i++) cout << a[i] << " ";
//		cout << "\n";
//		for(int i=1;i<=n;i++) cout << tong[i] << " ";
//		cout << "\n";
		for(int i=1;i<=n;i++){
			ans=min(ans,tong[i]);
		}
	}
	cout << ans << "\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> q;
	while(q--) solve();
	return 0;
} 
/*
0 1
5 2
1 2
2 3
3 4 
4 5
*/
