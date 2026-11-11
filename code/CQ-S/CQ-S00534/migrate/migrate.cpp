#include<bits/stdc++.h>
using namespace std;
#define maxn 1001000
#define int long long
int const inf =1e9;
vector<int> g[maxn];
int c,t,n,d,ans=0,x[maxn],dis[maxn],cnt[maxn];
queue<int> q;
void bfs(int beg){
	
	for(int j=1;j<=n;j++){
		dis[j]=inf;
		cnt[j]=0;

	}
	cnt[beg]=1;dis[beg]=0;
	q.push(beg);
	while(q.size()){
		int u=q.front();
		q.pop();
	
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			//printf("%d %d %d\n",u,v,dis[u]);
			if(dis[u]+1<dis[v]){
				cnt[v]=cnt[u];
				dis[v]=dis[u]+1;
				
					q.push(v);
				
				
				
			}
			else if(dis[u]+1==dis[v]){
				cnt[v]+=cnt[u];
			}
			
		}
	}
	for(int i=beg+1;i<=n;i++){
		//printf("%d %d %d %d\n",beg,i,dis[i],cnt[i]);
		if(cnt[i]==2){
			ans++;
		}
	}
}
int ed(int sx){
	int l=sx,r=n,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(x[mid]-x[sx]>d){
			r=mid-1;
		}
		else{
			res=l;
			l=mid+1;
		}
	}
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i].clear();
		}
		if(n<=5000){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					if(abs(x[i]-x[j])<=d){
						g[i].push_back(j);
					
					}
				}
			}
			for(int i=1;i<=n;i++){
				bfs(i);
			}
			cout<<ans<<'\n';
		}
		else{
			int div;
			int l=1,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(x[mid]-x[1]>d){
					r=mid-1;
				}
				else{
					div=l;
					l=mid+1;
				}
			}
			for(int i=1;i<div-1;i++){
				int edx=ed(i);
				if(edx>=div+2)continue;
				if(edx==div+1){
					ans+=max(0ll,ed(edx)-ed(div-1));
				}
			}
			ans+=max(0ll,ed(ed(div-1))-ed(div-1)) ;
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
