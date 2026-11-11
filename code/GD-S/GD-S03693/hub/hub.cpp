#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,sta[1055],f[1000005][21],dep[1000005],d[1000005],mx[1000005];
bool vis[1000005],bj[1000005];
vector<int>e[1000005];
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int y:e[x]){
		if(y==fa)continue;
		f[y][0]=x;
		dfs1(y,x);
	}
}
void dfs(int x,int fa){
	vis[x]=1;
	for(int y:e[x]){
		if(y==fa)continue;
		if(!bj[y])continue;
		dfs(y,x);
	}
}
bool pd(int x){
	for(int i=1;i<=n;i++){
		if(x>>(i-1)&1)bj[i]=1;
		else bj[i]=0;
		vis[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(bj[i]&&!vis[i])dfs(i,0),cnt++;
		if(cnt>2)return false;
	}
	return true;
}
int lca(int x,int y){
	if(x==y)return x;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
void dfs2(int x,int fa){
	dep[x]=dep[fa]+1;
	mx[x]=x;
	for(int y:e[x]){
		if(y==fa)continue;
		dfs2(y,x);
		if(dep[mx[x]]<dep[mx[y]])mx[x]=mx[y];
	}
}
bool check(int mid){
	int re=0,lst=0;
	for(int i=1;i<=n/2;i++){
		if(re==0){
			if(i+1>mid)re++,lst=i;
		}
		else{
			if(i+1-lst>mid)re++,lst=i;
		}
	}
	return re<=k;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++){
			e[i].clear(),dep[i]=0;
			for(int j=0;j<=20;j++)
				f[i][j]=0;
		}
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			e[x].push_back(y),e[y].push_back(x);
		}
		if(k==n){
			cout<<0<<"\n";
			continue;
		}
		if(c>=1&&c<=3){
			dfs1(1,0);
			for(int j=1;j<=20;j++)
				for(int i=1;i<=n;i++)
					f[i][j]=f[f[i][j-1]][j-1];
			int cnt=0,ans=INT_MAX;
			for(int i=0;i<(1<<n);i++){
				if(__builtin_popcount(i)!=k)continue;
				if(pd(i))sta[++cnt]=i;//,cout<<i<<"\n";
			}
			for(int i=1;i<=cnt;i++){
				int st=sta[i],val=0;
				for(int j=1;j<=n;j++)d[j]=INT_MAX;
				for(int j=1;j<=n;j++){
					if(st>>(j-1)&1){
						for(int k=1;k<=n;k++){
							if(st>>(k-1)&1)continue;
							d[k]=min(d[k],-2*dep[lca(j,k)]+dep[j]+dep[k]);
						}
					}
				}
				for(int j=1;j<=n;j++){
					if(st>>(j-1)&1)continue;
					val=max(val,d[j]);
				}
				ans=min(ans,val);
			}
			printf("%lld\n",ans);
			continue;
		}
		if(c==13||c==14){
			if(k>=n/2){
				cout<<1<<"\n";
				continue;
			}
			int l=1,r=n,ans=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(check(mid))r=mid-1,ans=mid;
				else l=mid+1;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(c==7){
			printf("%lld\n",n/2);
			continue;
		}
		cout<<n/k<<"\n";
	}
	return 0;
}/*

0 1
5 2
1 2
2 3
3 4
4 5

*/
