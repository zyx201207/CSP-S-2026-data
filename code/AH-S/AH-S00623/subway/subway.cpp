#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,ans=INT_MAX;
int w[500005];
int t[10005][10005];
int k[10005];
struct stu
{
	int a,b;
}p[100005];
vector<int> v[10005];
int v1[10005][10005];
int f[500005]={0};
void dfs(int a,int b,int sum)
{
	if(a==b)
	{
		ans=min(ans,sum);
		return ;
	}
	int l=v[a].size();
	for(int i=0;i<l;i++)
	{
		if(f[v[a][i]]==1) continue;
		f[v[a][i]]=1;
		dfs(v[a][i],b,sum+v1[a][v[a][i]]);
		f[v[a][i]]=0;
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i]*2;j++) cin>>t[i][j];
		for(int j=1;j<k[i];j++)
		{
			int s=0;
			for(int l=j+1;l<=k[i];l++)
			{
				s+=t[i][l*2-2];
				v1[t[i][j*2-1]][t[i][l*2-1]]=s;
				v1[t[i][l*2-1]][t[i][j*2-1]]=s;
				v[t[i][j*2-1]].push_back(t[i][l*2-1]);
				v[t[i][l*2-1]].push_back(t[i][j*2-1]);
			}
		}
	}
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		ans=INT_MAX;
		dfs(a,b,w[a]+w[b]);
		cout<<ans<<"\n";
	}
	return 0;
}
