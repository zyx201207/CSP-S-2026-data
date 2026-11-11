#include<bits/stdc++.h>
#define x0 x_0
#define x1 x_1
#define y0 y_0
#define y1 y_1
#define yn y_n
#define j0 j_0
#define j1 j_1
#define jn j_n
#define k0 k_0
#define k1 k_1
#define d0 d_0
#define d1 d_1
#define LL long long
#define LD long double
#define Big __int128
#define STR string
#define US unsigned
#define ZPB push_back
#define ZPF push_front
#define PPB pop_back
#define PPF pop_front
#define next NXTNXT
#define UPB upper_bound
#define LWB lower_bound
#define mem(x,val) memset(x,val,sizeof(x))
using namespace std;
const int N=1000010,INTmex=(int)1e9+2;
int c,test,n,k,dep[N],res,rans,fa[N];
bitset<N> cho;
vector<int> G[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	if(cho[x]) res=min(res,dep[x]-1);
	for(int u:G[x]){
		if(u==fa) continue;
		dfs(u,x);
	}
	return ;
}
int find(int x) {return (fa[x]==x ? x : fa[x]=find(fa[x]));}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v) return ;
	fa[u]=v;
}
void Init(){
	rans=INTmex;
	for(int i=0;i<=n;++i) G[i].clear();
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>test;
	while(test--){
		Init(),cin>>n>>k;
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v,G[u].ZPB(v),G[v].ZPB(u);
		}
		for(int S=0;S<(1<<n);++S){
			int cnt=0;
			for(int i=1;i<=n;++i) cho[i]=((S>>(i-1))&1),cnt+=cho[i];
			if(cnt!=k) continue;
			for(int i=1;i<=n;++i) fa[i]=i;
			for(int i=1;i<=n;++i){
				if(!cho[i]) continue;
				for(int u:G[i]){
					if(!cho[u]) continue;
					merge(i,u);
				}
			}
			int res=0,res2=0,fla=1;
			for(int i=1;i<=n;++i){
				if(!cho[i]) continue;
				int x=find(i);
				if(!res) res=x;
				else if(x!=res){
					if(!res2) res2=x;
					else if(x!=res2) {fla=0;break;}
				}
			}
//			cerr<<"res="<<res<<" res2="<<res2<<" fla="<<fla<<"\n";
			if(!fla) continue;
			int ans=0;
			for(int i=1;i<=n;++i)
				if(!cho[i]){
					::res=INTmex,dep[i]=0;
					dfs(i,i);
					ans=max(ans,::res);
				}
			rans=min(rans,ans);
		}
		cout<<rans<<"\n";
	}
	return 0;
}

/*
input1:

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

output1:

1
2
 
*/ 
