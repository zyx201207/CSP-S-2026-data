#include<iostream>
#include<vector>
using namespace std;
long long T,n,su,ans,a[1000001];
vector<int>v[1000001];
bool boo[1000001];
long long getfather(long long x)
{
	while(a[x]!=x)
	  x=a[x]=a[a[x]];
	return x;
}
void union1(long long j,long long k)
{
	a[getfather(j)]=getfather(k);
}
long long k;
void dfs2(long long x,long long fa,long long dep)
{
	if(boo[x]==true)
	  su=min(su,dep);
	for(int z=0;z<v[x].size();z++)
	{
		if(v[x][z]==fa)
		  continue;
		dfs2(v[x][z],x,dep+1);
	}
}
void dfs(long long x,long long cnt)
{
	if(cnt==k)
	{
		long long sum=0;
		for(int z=1;z<=n;z++)
		  a[z]=z;
		for(int z=1;z<=n;z++)
		  if(boo[z]==true)
			for(int y=0;y<v[z].size();y++)
			  if(boo[v[z][y]]==true)
				union1(z,v[z][y]);
		for(int z=1;z<=n;z++)
		  sum+=boo[z]*(a[z]==z);
		if(sum>2)
		  return;
		sum=0;
		for(int z=1;z<=n;z++)
		{
			su=1e18;
			dfs2(z,0,0);
			sum=max(sum,su);
		}
		ans=min(ans,sum);
		return;
	}
	if(x>n)
	  return;
	boo[x]=true;
	dfs(x+1,cnt+1);
	boo[x]=false;
	dfs(x+1,cnt);
}
void work()
{
	ans=1e18;
	cin>>n>>k;
	for(int z=1;z<=n;z++)
	  v[z].clear();
	for(int z=1;z<n;z++)
	{
		long long j,l;
		cin>>j>>l;
		v[j].push_back(l);
		v[l].push_back(j);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
void work2()
{
	cin>>n>>k;
	for(int z=1;z<n;z++)
	{
		long long j,l;
		cin>>j>>l;
	}
	if(k==1)
	  cout<<((n+1)/2-k)/2+1<<"\n";
	else
	  cout<<((n+1)/2-k)/4+1<<"\n";
}
long long c;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	if(c==13||c==14)
	  for(int z=1;z<=T;z++)
		work2();
	else
	  for(int z=1;z<=T;z++)
		work();
	return 0;
}
