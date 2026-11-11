#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,ans;
int maxn,mn,s;
int fl[1000001],lst[1000001],dep[1000001];
vector<int>vis[1000001];
void dfs(int x,int fa){
	if(x==fa)dep[x]=0;
	if(dep[x]>maxn){
		maxn=dep[x];
		mn=x;
	}
	for(auto v:vis[x]){
		if(v==fa)continue;
		dep[v]=dep[x]+1;
		lst[v]=x;
		dfs(v,x);
	}
}
int find(int x,int fa,int sum){
	if(fl[x])return sum;
	int aans=INT_MAX;
	for(auto v:vis[x]){
		if(v==fa)continue;
		aans=min(aans,find(v,x,sum+1));
	}
	return aans;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		maxn=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			vis[i].clear();
			fl[i]=0;
		}
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			vis[u].push_back(v);
			vis[v].push_back(u);
		}
		dfs(1,1);
		maxn=0;
		s=mn;
		lst[mn]=mn;
		dfs(mn,mn);
		int ha=maxn/2;
		while(ha){
			mn=lst[mn];
			ha--;
		}
		queue<int>q;
		int tot=0;
		q.push(mn);
		fl[mn]=1;
		while(tot<k){
			int f=q.front();
			q.pop();
			tot++;
			for(auto v:vis[f]){
				if(!fl[v]){
					q.push(v);
					fl[v]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,find(i,i,0LL));
		}
		cout<<ans<<"\n";
	}
	return 0;
}//0 2 5 2 1 2 2 3 3 4 4 5 10 3 1 2 1 3 2 4 2 5 3 6 3 7 3 8 7 9 9 10
