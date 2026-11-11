#include<bits/stdc++.h>
using namespace std;
int n,k,id,t,l[1000005],flags[15],cnt,minn,ans;
vector<int>tr[1000005];
void dfs2(int x)
{
	flags[x]=1;
	for(int to:tr[x]){
		if(flags[to]||!l[to]) return;
		dfs2(to);
	}
}
void dfs3(int x,int s,int fa)
{
	if(l[x]) minn=min(minn,s);
	for(int to:tr[x]){
		if(to!=fa) dfs3(to,s+1,x); 
	}
}
void dfs(int x,int s)
{
	if(x==n+1)
	{
		if(s!=k) return;
		memset(flags,0,sizeof(flags));
		cnt=0;
		for(int i=1;i<=n;i++){
			if(!l[i]||flags[i]) continue;
			cnt++;
			if(cnt>2) return;
			dfs2(1);
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			minn=1e9;
			dfs3(1,0,0);
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
		return;
	}
	l[x]=1,dfs(x+1,s+1);
	l[x]=0;dfs(x+1,s);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>id>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			tr[x].emplace_back(y),tr[y].emplace_back(x);
		}
		ans=1e9;
		dfs(1,0);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) tr[i].clear();
	}
	return 0;
}
