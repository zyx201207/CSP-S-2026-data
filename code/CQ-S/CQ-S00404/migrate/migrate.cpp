#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int c,t;
int n,w,a[MAXN],cnt,ans[MAXN],tag[MAXN],nxt[MAXN],dis[MAXN];
vector<int>g[MAXN];
void dfs(int x,int fa){
	for(auto v:g[x]){
		if(v==fa)continue;
		dis[v]=dis[x]+1;
		dfs(v,x);
	}
}
void dfs2(int x,int fa,int time){
	dis[x]--;
	for(auto v:g[x]){
		if(v==fa)continue;
		dfs2(v,x,time);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&w);
		for(int i=1;i<=n+1;i++){
			a[i]=ans[i]=nxt[i]=dis[i]=tag[i]=0;
			g[i].clear();
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n-1;i++){
			int l=i+1,r=n,answ=0;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[mid]-a[i]<=w){
					l=mid+1;
					answ=mid;
				}else{
					r=mid-1;
				}
			}
			if(answ==0)continue;
			nxt[i]=answ;
			g[i].push_back(nxt[i]);
			g[nxt[i]].push_back(i);
		}
		for(int k=n;k>=1;k--){ 
			if(dis[k])continue;
			dfs(k,-1);
			sort(g[k].begin(),g[k].end());
			for(int j=g[k].size()-1;j>=1;j--){
				for(int i=k-1;i>=1;i--){
					if(dis[i]==0)break;
					if(nxt[i]==i+1){
						ans[i]=(ans[i]+ans[i+1]);
					}else{
						int l=i,r=nxt[i],answ=n;
						while(l<=r){
							int mid=(l+r)/2;
							if(dis[i]==dis[mid]){
								l=mid+1;
								answ=mid;
							}else{
								r=mid-1;
							}
						}
						answ++;
						if(nxt[i]-answ+1==2){
							ans[i]++;
						}
					}
				}	
				dfs2(g[k][j],k,g[k].size()-j-1);
			}
		}
		long long sumans=0;
		for(int i=1;i<=n;i++){
			sumans+=ans[i];
		}	
		printf("%lld\n",sumans);	
		
	}
	return 0;
}
