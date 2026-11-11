#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000007],mn[2000007],cnt[2000007],ans,vis[2000007],p;
vector<int> g[2000007];
queue<int> q;
void dfs(int st){
	for(int i=1;i<=n;i++){
		mn[i]=1e9;
		cnt[i]=0;
		vis[i]=0;
	}
	mn[st]=0;
	vis[st]=1;
	q.push(st);
	while(!q.empty()){
		p=q.front();
		q.pop();
		vis[p]=0;
		for(int i=0;i<g[p].size();i++){
			if(!vis[g[p][i]]){
				if(mn[g[p][i]]>mn[p]+1){
					mn[g[p][i]]=mn[p]+1;
					cnt[g[p][i]]=1;
					q.push(g[p][i]);
				}else if(mn[g[p][i]]==mn[p]+1){
					cnt[g[p][i]]++;
					q.push(g[p][i]);
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					g[a[i]].push_back(a[j]);
					g[a[j]].push_back(a[i]);
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			dfs(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
