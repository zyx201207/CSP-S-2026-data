#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int w[N],t[N],dep[N],vis[N],cnt[N];
int c,n,m,d,q;
int cnt1,x1=0;
vector<int> e[N];
void dfs(int x,int fa){
	if(x1==m) return;
	dep[x]=dep[fa]+1;
	vis[x]=1;
	x1++;
	if(cnt[fa]!=0) cnt1+=cnt[fa]; 
	for(int i:e[x])
	{
		if(i==fa) continue;
		if(vis[i]!=0&&dep[i]<=dep[x]) 
		{
			dep[x]=dep[i]+1;
			if(cnt[i]!=0) cnt1+=cnt[i];
		}
		if(vis[i]!=0&&dep[i]>=dep[x]) dep[i]=dep[x]+1;
		if(vis[i]==0) dfs(i,x);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int b=-1;
	for(int i=1;i<=q;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a=0;
			cin>>a;
			if(t[a]!=0) cnt[a]++;
			cin>>t[a];
			e[b].push_back(a);
			e[a].push_back(b);
			b=a;
		}
	}
	if(c==7||c==8||c==9||c==10||c==11)
	{
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+t[x]+t[y]<<"\n";
		}
		return 0;
	}
	dfs(1,0);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int ans=abs((dep[x]-dep[y])+cnt1)*t[x]+w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
