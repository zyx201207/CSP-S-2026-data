#include<bits/stdc++.h>
using namespace std;
namespace ld{
	const int N=2e6+5;
	const int inf=1e9;
	int CASE_BH,T;
	int n,K;vector<int>ed[N];
	int dep[N],mxd[N],sxd[N],cnt[N],mn[N];
	void dfs(int u,int la,int mid){
		dep[u]=dep[la]+1,mxd[u]=dep[u],sxd[u]=0;
		cnt[u]=0;
		for(int v:ed[u]){
			if(v==la)continue;
			dfs(v,u,mid);
			cnt[u]+=cnt[v]+(mxd[v]-dep[v]>=mid);
			if(mxd[v]>mxd[u])sxd[u]=mxd[u],mxd[u]=mxd[v];
			else if(mxd[v]>sxd[u])sxd[u]=mxd[v];
		}		
	//	cerr<<"?:"<<u<<' '<<mxd[u]-dep[u]<<' '<<cnt[u]<<'\n';
	}
	void Chkout(int u,int la,int out,int mid){
		mn[u]=inf;
		if(out<=mid)mn[u]=min(mn[u],cnt[u]+1);
		for(int v:ed[u]){
			if(v==la)continue;
			int x=mxd[v]==mxd[u]?sxd[u]:mxd[u];
			Chkout(v,u,max(out,x-dep[u])+1,mid);
			mn[u]=min(mn[u],mn[v]);
		}	
	}
	int f[N];
	bool check(int mid){
		int ans=inf;
		for(int j=1;j<=n;j++){
			dfs(j,0,mid);
			ans=min(ans,cnt[j]+1);//Ñ¡Ôñj 
			
			if(ed[j].size()==1)continue;
			vector<pair<int,int> >vc; 
			set<pair<int,int> >st;
			for(int v:ed[j])Chkout(v,j,-inf,mid),f[v]=mn[v],vc.push_back({mxd[v],v}),st.insert({mn[v],v});
			sort(vc.begin(),vc.end());		
			for(int v:ed[j]){
				pair<int,int>mx,sx;
				for(int j=(int)vc.size()-1;j>=0;j--){
					auto[d,v2]=vc[j];
					if(v2==v)continue;
					if(!mx.first)mx={d,v2};
					else {
						sx={d,v2};
						break;
					}
				}
				Chkout(v,j,max(1,mxd[sx.second]),mid);
				ans=min(ans,mn[v]+f[mx.second]);
				if(sx.first){
					Chkout(v,j,mxd[mx.second],mid);
					st.erase({v,f[v]});
					st.erase({mx.second,f[mx.second]});
					ans=min(ans,mn[v]+(st.begin()->first));
					st.insert({v,f[v]});
					st.insert({mx.second,f[mx.second]});					
				}
			}
			if(ans<=K)return 1; 
		}
		return ans<=K;
	}
	int main(){
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		cin>>CASE_BH>>T;
		while(T--){
			cin>>n>>K;
			for(int i=1;i<=n;i++)ed[i].clear();
			for(int i=1,x,y;i<n;i++)cin>>x>>y,ed[x].push_back(y),ed[y].push_back(x);
			int l=0,r=n,to=-1;
			while(l<=r){
				int mid=l+r>>1;
				if(check(mid))to=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<to<<'\n';
		}
		
		return 0;
	}
}
int main(){
	ld::main();
	return 0;
}
