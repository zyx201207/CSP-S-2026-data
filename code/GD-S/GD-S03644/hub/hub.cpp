#include<bits/stdc++.h>
using namespace std;enum{N=1000005};
int Case,n,k,ans,a[N];vector<int>s[N];
void dfs(int x,int fa,int d){a[x]=min(a[x],d);
	for(int p:s[x]) if(p^fa) dfs(p,x,d+1);}
int main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	for(scanf("%d%*d",&Case);~scanf("%d%d",&n,&k);printf("%d\n",ans)){
		for(int i=1;i<=n;s[i++].clear());ans=n;
		set<pair<int,int>>ed;for(int i=n,u,v;--i;) scanf("%d%d",&u,&v),
			ed.insert({u,v}),s[u].push_back(v),s[v].push_back(u);
		if(Case==13||Case==14){ans=n-k*2+14>>3;continue;}
		for(int i=1;i<1<<n;i++) if(__builtin_popcount(i)==k){
			int cnt=k;for(int j=1;j<=n;j++) if(i&1<<j-1)
				for(int k=j+1;k<=n;k++) if(i&1<<k-1)
					cnt-=ed.count({j,k});if(cnt>2) continue;
			for(int j=1;j<=n;a[j++]=n);
			for(int j=1;j<=n;j++) if(i&1<<j-1) dfs(j,0,0);cnt=0;
			for(int j=1;j<=n;cnt=max(cnt,a[j++]));ans=min(ans,cnt);
		}
	}
	return 0;
}