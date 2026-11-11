#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int x[1000010];
int ans=0;
int dis[5010],sum[5010];
int findl(int y){
	int l=1,r=n,ans=y;
	y=x[y]-d;
	while(l<=r){
		int mid=(l+r)/2;
		if(x[mid]>=y){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
int findr(int y){
	int l=1,r=n,ans=y;
	y=x[y]+d;
	while(l<=r){
		int mid=(l+r)/2;
		if(x[mid]<=y){
			ans=mid;
			l=mid+1; 
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
int lx[1000010],rx[1000010];
int vis[5010][5010];
void bfs(int x){
	for(int i=1;i<=n;++i){
		sum[i]=0;
		dis[i]=2e18;
	}
	queue<int> q;
	q.push(x);
	dis[x]=0;
	sum[x]=1;
	while(q.size()){
		int nd=q.front();
		q.pop();
		for(int i=lx[nd];i<=rx[nd];++i){
			if(dis[i]>dis[nd]+1){
				dis[i]=dis[nd]+1;
				sum[i]=sum[nd];
				vis[nd][i]=x;
				q.push(i);
			}
			else if(dis[i]==dis[nd]+1&&vis[nd][i]!=x){
				sum[i]+=sum[nd];
				q.push(i);
				vis[nd][i]=x;
			}
		}
	}
	for(int i=x+1;i<=n;++i){
		if(sum[i]==2){
			ans++;
		}
	}
}
bool chk(){
	int d=x[2]-x[1];
	for(int i=2;i<n;++i){
		if(x[i+1]-x[i]!=d){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;++i){
			lx[i]=findl(i);
			rx[i]=findr(i);
		}
		for(int i=1;i<=n;++i){
			bfs(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
