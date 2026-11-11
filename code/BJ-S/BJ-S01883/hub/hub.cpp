#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x":"<<(x)<<' '
#define dbe(x) cerr<<#x":"<<(x)<<'\n'
#define eb emplace_back
#define ep emplace
#define endl '\n'
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using tp=tuple<int,int>;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,K;
		cin>>n>>K;
		vector<vi>G(n);
		vector<tp>es(n-1);
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;u--,v--;
			es[i-1]={u,v};
			G[u].eb(v),G[v].eb(u);
		}
		if(c==13||c==14){
			int m=n/2;
			if(K==n)cout<<0<<endl;
			else if(K>=m)cout<<1<<endl;
			else{
				if(m&1)m++;
				int o1=m/2,o2=K/2;
				cout<<(o1-o2+1)/2+1<<endl;
				//cout<<(o1+1)/2-o2/2+1<<endl;
			}
			continue;
		}
		auto work=[&](int rt,int irt){
			int md=-1,sz=0;{
				int far=-1,len=-1;
				auto dfs=[&](int u,int fa,int dep,auto&&dfs)->void {
					if(dep>len)len=dep,far=u;
					sz++;
					for(int v:G[u]){
						if(v==fa||v==irt)continue;
						dfs(v,u,dep+1,dfs);
					}
				};
				dfs(rt,irt,0,dfs);
				int l=far;far=-1,len=-1;sz=0;
				dfs(l,-1,0,dfs);
				int r=far;
				vi lst={r};
				auto dfs2=[&](int u,int fa,auto&&dfs2)->bool {
					if(u==r)return true;
					for(int v:G[u])if(v!=fa&&dfs2(v,u,dfs2)){
						lst.eb(u);
						return true;
					}
					return false;
				};
				dfs2(l,-1,dfs2);
				md=lst[lst.size()/2];
			}
			//dbg(rt),dbg(md),dbe(sz);
			int k=min(K-1,sz);
			vl s;s.reserve(sz);
			auto dfs=[&](int u,int fa,auto&&dfs)->int {
				int d=0;
				for(int v:G[u]){
					if(v==fa||v==irt)continue;
					d=max(d,dfs(v,u,dfs)+1);
				}
				s.eb(d);
				return d;
			};
			dfs(md,-1,dfs);
			sort(s.begin(),s.end(),greater<int>());
			int sc=0;
			for(int i=(int)s.size()-1;i>=0;i--){
				int o=s[i];
				s[i]=sc;
				sc=o+1;
			}
			s.resize(k);
			//for(int v:s)cerr<<v<<' ';cerr<<endl;
			return s;
		};
		ll ans=1e18;
		for(auto [r1,r2]:es){
			//dbg(r1),dbe(r2);
			vl d1=work(r1,r2),d2=work(r2,r1);
			for(int i=max(1,K-(int)d2.size());i<=d1.size();i++){
				//dbg(i-1),dbg(K-i-1),dbe(max(d1[i-1],d2[K-i-1]));
				ans=min(ans,max(d1[i-1],d2[K-i-1]));
			}
		}
		//dbe(ans);
		cout<<ans<<endl;
	}
	
	return 0;
}