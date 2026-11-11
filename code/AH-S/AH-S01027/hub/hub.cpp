#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
const int N=2000005;
int c,t,n,k,ct1=0,ct2,mid;
vector<int> g[N];
bitset<2005> vis,in;
bool flag,fl;
int f[2005][2005];
void calc(int now){
	rep(i,1,n){
		if(!in[i]&&f[now][i]){
			in[i]=1,calc(i);
		}
	}
}
int ress;
void dd(int now,int s){
	if(s>mid)return ;
	if(in[now]){
		ress=min(ress,s);return ;
	}
	rep(i,1,n){
		if(f[now][i]){
			dd(now,s+1);
		}
	}
}
bool check1(){
	in.reset();int cc=0;
	rep(i,1,n){
		if(!in[i])calc(i),++cc;
		if(cc>2)return 0;
	} if(cc!=2){
		return 0;
	} rep(i,1,n){
		ress=0x3f3f3f3f;dd(i,0);
		if(ress>mid)return 0;
	} return 1;
}
void dfs(int now,int c1){
	if(c1==k){
		flag|=check1();
		
		return ;
	}
	rep(i,now+1,n){
		if(!vis[i]){
			vis[i]=1,dfs(i,c1+1);
			vis[i]=0;
			if(flag)return ;
		}
	}
}
bool check(){
	for(int i=1;i<=n;++i){
		vis.reset();vis[i]=1;dfs(i,1),vis[i]=0;if(flag)return 1;
	}
}
int main(){
	 freopen("hub.in","r",stdin);
	 freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;rep(i,1,n)rep(j,1,n)f[i][j]=0;
		rep(i,1,n)g[i].clear();
		rep(i,1,n-1){
			int u,v;
			cin>>u>>v;f[u][v]=f[v][u]=1;
		} int l=0,r=n;
		while(l<=r){
			mid=l+r>>1;
			if(check())r=mid-1;
			else l=mid+1;
		} cout<<r-1<<'\n';
	}
	return 0;
}
