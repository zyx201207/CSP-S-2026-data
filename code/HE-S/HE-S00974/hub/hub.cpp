#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int> v[100005];
int la[100005];
long long dis[100005];
int vis[100004];
int per[100005];
long long z=0;
int n,k;
long long ans=2e9;
void work(int x){
	for(int i=0;i<v[x].size();i++){
		int u=v[x][i];
		vis[u]=1;
	}
}
void init(int x,int fa){
	dis[x]=dis[fa]+1;
	for(int i=0;i<v[x].size();i++){
		int u=v[x][i];
		if(u==fa) continue;
		init(u,x);
	}
}
long long solve(){
	int cnt=0;
	for(int i=1;i<=n+1;i++){
		vis[i]=0;
		per[i]=0;
	}
	for(int i=1;i<=k;i++){
		per[la[i]]=1;
		if(vis[la[i]]==0){
			vis[la[i]]=1;
			cnt++;
			work(la[i]);
		} 
	}
	if(cnt>2){
		return 0ll;
	}
	long long res=2e9;
	for(int i=1;i<=n;i++){
		if(per[i]==1) continue;
		for(int j=1;j<=k;j++){
			res=min(res,abs(dis[i]-dis[la[j]]));
		}
	}
	return res;
}
void dfs(int x,int cnt){
	if(cnt==k){
		long long sum=solve();
		ans=min(ans,sum);
		return ;
	}
	for(int i=x+1;i<=n;i++){
		z++;
		la[z]=i;
		dfs(i,cnt+1);
		z--;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		init(1,0);
		dfs(0,1);
		cout<<ans<<endl;
	}
	return 0;
}
