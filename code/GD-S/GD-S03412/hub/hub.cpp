#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,cnt,ans,fa[1000005],dis[1000005];
bool vis[1000005];
vector<int> a[1000005];
queue<int> q;
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x){
	if(x!=fa[x])return fa[x]=find(fa[x]);
	return x;
}
void merge(int x,int y){
	int r1=find(x);
	int r2=find(y);
	if(r1!=r2){
		fa[r1]=r2;
		cnt--;
	}
}
int check(int x,int y){
	q.push(x);
	q.push(y);
	for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f3f3f3f3f;
	dis[x]=dis[y]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:a[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)res=max(res,dis[i]);
	return res;
}
int dfs(int num){
	for(int i=1;i<=n;i++)vis[i]=false;
	cnt=0;
	for(int j=1;j<=n;j++){
		if((num>>(j-1))&1){
			cnt++;
			vis[j]=true;
		}
	}
	if(cnt!=k)return 0x3f3f3f3f3f3f3f3f;
	for(int j=1;j<=n;j++){
		if(vis[j]){
			for(auto v:a[j]){
				if(vis[v]){
					merge(j,v);
				}
			}
		}
	}
	if(cnt>2)return 0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			q.push(i);
			dis[i]=0;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:a[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)res=max(res,dis[i]);
	return res;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ans=0x3f3f3f3f3f3f3f3f;
		if(c==7){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=min(ans,check(i,j));
				}
			}
		}else if(c<=3){
			for(int i=0;i<(1<<n);i++){
				init();
				ans=min(ans,dfs(i));
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)a[i].clear();
	}
	return 0;
} 
