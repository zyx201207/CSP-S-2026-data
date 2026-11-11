#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4005;
int u[N],v[N],dep[N],id[N<<1],nxt[N<<1];
int dis[N],mx,mid,st[N],top,s[N],cnt1[N],cnt2[N],c,t,n,k,ans,i;
void dfs(int u,int fa){
	dis[u]=dis[fa]+1;st[++top]=u;
	if(dis[u]>dis[mx]) mx=u,mid=st[top/2+1];
	for(int j=dep[u];j<dep[u+1];j++){
		int v=nxt[j];
		if(id[j]==i||v==fa) continue;
		dfs(v,u);
	}
	top--;
}
void dfs1(int u,int fa){
	s[u]=0;
	for(int j=dep[u];j<dep[u+1];j++){
		int v=nxt[j];
		if(id[j]==i||v==fa) continue;
		dfs1(v,u);
		s[u]=max(s[u],s[v]+1);
	}
	cnt1[s[u]]++;
}
void dfs2(int u,int fa){
	s[u]=0;
	for(int j=dep[u];j<dep[u+1];j++){
		int v=nxt[j];
		if(id[j]==i||v==fa) continue;
		dfs2(v,u);
		s[u]=max(s[u],s[v]+1);
	}
	cnt2[s[u]]++;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			cin>>n>>k;ans=n;
			for(i=1;i<n;i++){
				cin>>u[i]>>v[i];
				dep[u[i]]++;dep[v[i]]++;
			}
			for(i=1;i<=n;i++) dep[i+1]+=dep[i];
			for(i=1;i<n;i++){
				id[--dep[u[i]]]=i;
				nxt[dep[u[i]]]=v[i];
				id[--dep[v[i]]]=i;
				nxt[dep[v[i]]]=u[i];
			}
			for(i=1;i<n;i++){
				mx=u[i];
				dfs(u[i],0);mid=u[i];
				dfs(mx,0);
				dfs1(mid,0);mx=v[i];
				dfs(v[i],0);mid=v[i];
				dfs(mx,0);
				dfs2(mid,0);
				for(int j=1;j<=n;j++){
					cnt1[j]+=cnt1[j-1];
					cnt2[j]+=cnt2[j-1];
				}
				int l=1,r=n,mn=n;
				while(l<=r){
					mid=(l+r)>>1;
					if(n-(cnt1[mid-1]+cnt2[mid-1])<=k) r=mid-1,mn=mid;
					else l=mid+1;
				}
				ans=min(ans,mn);
				for(int j=0;j<=n;j++) cnt1[j]=cnt2[j]=0;
			}
			for(int i=0;i<=n+1;i++) dep[i]=0;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
