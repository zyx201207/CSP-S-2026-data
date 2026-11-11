#include<bits/stdc++.h>
using namespace std;
namespace froepen{
	int c,t,n,k,ans;
	int hd[1000005],nxt[2000005],to[2000005],cnt;
	void add(int u,int v){
		nxt[++cnt]=hd[u];
		hd[u]=cnt;
		to[cnt]=v;
	}
	bool vst1[1000005];
	bool jidi[1000005];
	void dfs2(int u,int f){
		vst1[u]=1;
		for(int i=hd[u];i;i=nxt[i]){
			int v=to[i];
			if(v!=f&&jidi[v]){
				dfs2(v,u);
			}
		}
	}
	bool vst2[1000005];
	int dl[1000005],l,r;
	int d[1000005];
	void dfs1(int i,int cnt){
		if(i>n){
			if(cnt<k)return;
			for(int i=1;i<=n;i++){
				vst1[i]=0;
			}
			int t=0;
			for(int i=1;i<=n;i++){
				if(jidi[i]&&!vst1[i]){
					t++;
					dfs2(i,i);
				}
			}
			if(t>2)return;
			l=0,r=-1;
			for(int i=1;i<=n;i++){
				if(jidi[i]){
					dl[++r]=i;
					vst2[i]=1;
				}
				else vst2[i]=0;
				d[i]=0;
			}
			int s=0;
			while(l<=r){
				int u=dl[l++];
				for(int i=hd[u];i;i=nxt[i]){
					int v=to[i];
					if(!vst2[v]){
						vst2[v]=1;
						d[v]=d[u]+1;
						s=max(s,d[v]);
						dl[++r]=v;
					}
				}
			}
			ans=min(ans,s);
			return;
		}
		if(cnt<k){
			jidi[i]=1;
			dfs1(i+1,cnt+1);
		}
		jidi[i]=0;
		dfs1(i+1,cnt);
	}
	int main(){
		cin>>c>>t;
		while(t--){
			cin>>n>>k;
			cnt=0;
			ans=1000000000;
			for(int i=1;i<=n;i++){
				hd[i]=0;
			}
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				add(u,v);
				add(v,u);
			}
			dfs1(1,0);
			cout<<ans<<'\n';
		}
		return 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	froepen::main();
	return 0;
}
