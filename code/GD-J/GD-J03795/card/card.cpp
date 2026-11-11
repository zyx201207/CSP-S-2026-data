#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[500005],dp[500005],maxx[300005],ans[300005];
vector<int> g[500005];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx[a[i]]=max(maxx[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		if(i==maxx[a[i]]){
			g[i].push_back(i+1);
			d[i+1]++;
		}else{
			g[i].push_back(maxx[a[i]]);
			d[maxx[a[i]]]++;
		}
	}
	for(int i=1;i<=n;i++)if(d[i]==0)q.push(i);
	for(int i=1;i<=n;i++)dp[i]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			dp[v]+=dp[u];
			d[v]--;
			if(a[v]!=a[u])ans[a[u]]+=dp[u];	
			if(d[v]==0)q.push(v);
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
