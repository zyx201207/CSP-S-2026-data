#include<bits/stdc++.h>
using namespace std;
namespace ld{
	typedef long long ll;
	const int N=2e6+5;
	int n,fa[N];ll D,X[N];
	vector<int>ed[N];
	ll sum1[N],sum2[N],f2[N],Ans;
	int dep[N];
	struct fenwick{
		int ft[N];
		int lowbit(int x){return x&(-x);}
		void add(int p,int v){
			for(;p<=n;p+=lowbit(p))ft[p]+=v;
		}
		int ask(int p){
			int res=0;
			for(;p;p-=lowbit(p))res+=ft[p];
			return res;
		}
	}ft;
	void dfs(int u,int la,int p2,int pe){
		dep[u]=dep[la]+1;
		//第一个两个铃铛的位置
		//第一个终结的位置 
		if(la){
			if(dep[la]>=max(dep[fa[p2]],dep[pe]))Ans+=ft.ask(dep[la])-ft.ask(max(dep[fa[p2]],dep[pe]));
			Ans+=max(0ll,sum1[fa[p2]]-sum1[pe]); 
		//	cerr<<"ans: "<<u<<' '<<fa[p2]<<' '<<pe<<' '<<sum1[fa[p2]]-sum1[pe]<<'\n';
		} 
		for(int v:ed[u]){
			int x=0;
			if(la){
				x=fa[u]-u;
				if(u-1>v&&fa[u-1]>u)x-=(fa[u-1]-u);
			}
			sum1[u]=sum1[la]+x;
			
		 	x=0;
		 	if(la){
			 	if(u-1>v&&fa[u-1]>u){
			 		x=fa[u-1]-u;
			 		if(u-2>v&&fa[u-2]>u)x-=(fa[u-2]-u);
				 }	 		
			}
			sum2[u]=sum2[la]+x,f2[u]=x;	
			ft.add(dep[u],f2[u]);
			if(u-1>v&&la-1>u&&(X[la-1]-X[u-1])<=D){
		//		cerr<<"?:"<<u<<' '<<la<<'\n';
				ft.add(dep[la],-f2[la]);
			}
			if(la&&u-2>v&&X[la]-X[u-1]<=D&&X[la]-X[u-2]<=D)dfs(v,u,u,la);
			else if(la&&u-1>v&&X[la]-X[u-1]<=D)dfs(v,u,u,p2);
			else if(p2&&u-1>v&&X[p2-1]-X[u-1]<=D)dfs(v,u,p2,p2);
			else dfs(v,u,p2,pe);
			if(u-1>v&&la-1>u&&(X[la-1]-X[u-1])<=D){
				ft.add(dep[la],f2[la]);
			}			
			
			ft.add(dep[u],-f2[u]);
		}
		
	}
	int main(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		int CASE_BH,T;
		cin>>CASE_BH>>T;
		while(T--){
			cin>>n>>D;
			for(int i=1;i<=n;i++)cin>>X[i],fa[i]=0,ed[i].clear();
			int p=n;
			for(int i=n;i>=1;i--){
				while(X[p]-X[i]>D)--p;
				if(p!=i)fa[i]=p,ed[fa[i]].push_back(i);//cerr<<i<<' '<<fa[i]<<'\n';	
			}
			Ans=0;
			for(int i=1;i<=n;i++)if(!fa[i])dfs(i,0,0,0);
			cout<<Ans<<'\n';
			
		}
		
		
		return 0;
	}
}
int main(){
	ld::main();
	return 0;
}
