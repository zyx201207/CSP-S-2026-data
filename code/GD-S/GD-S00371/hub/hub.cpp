#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tt{
	int x,l;
}; 
int ca,T,n,m,x,y,ans,vis[1000005],f[1000005],mp[1000005];
vector<int> q[1000005];
int distance(int st,int en){
	for(int i=1;i<=n;i++) mp[i]=0;
	queue<tt> v;
	v.push({st,0});mp[st]=1;
	while(v.size()){
		int x=v.front().x,l=v.front().l;v.pop();
		if(x==en) return l;
		for(int i=0;i<q[x].size();i++) if(mp[q[x][i]]==0) mp[q[x][i]]=1,v.push({q[x][i],l+1});
	} 
	return 0;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool pd(){
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		for(int j=0;j<q[i].size();j++){
			if(vis[q[i][j]]){
				int x1=find(i),y1=find(q[i][j]);
				if(x1!=y1) f[y1]=x1;
			} 
		}
	}
	int qwq=0;
	for(int i=1;i<=n;i++) if(vis[i]){
		if(find(i)==i) qwq++;
	}
	if(qwq<=2) return 1;
	return 0;
}
int cy3(){
	int ct=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int ctt=1e18;
		for(int j=1;j<=n;j++) if(vis[j]) ctt=min(distance(i,j),ctt); 
		ct=max(ct,ctt);
	}
	return ct;
} 
void dfs(int i,int s){
	if(i==n+1){
		if(m==s&&pd()) ans=min(ans,cy3());
	}else{
		vis[i]=1;
		dfs(i+1,s+1);
		vis[i]=0;
		dfs(i+1,s);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>ca>>T;
	while(T--){
		cin>>n>>m;ans=1e18;
		for(int i=1;i<=n;i++) q[i].clear();
		for(int i=1;i<n;i++) cin>>x>>y,q[x].push_back(y),q[y].push_back(x);
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
} 
