#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[505],k,f[500005],t[500005],x[100005],y[100005];
int mapn[20000][20000];
int q[500005],vis[500005]={0},step[500005];
int minn=0x3f3f3f;
void search()
{
	/*int ch;
	if(root==endn)return;
	for(int i=1;i<=n;i++)
	{
		if(mapn[root][i]!=0)
		{
			if(dp[root]+mapn[root][i]<dp[i])
			{
				ch=i;
				dp[i]=dp[root]+mapn[root][i];
			}
		}
	}
	search(ch,endn);*/
	
	int head=1,tail=1;
	q[tail]=x[p];
	vis[x[p]]=1;
	step[tail]=0;
	tail++;
	while(head<tail)
	{
		int nx=q[head];
		int nstep=step[head];
		head--;
		if(nx==y[p])
		{
			if(nstep<minn)minn=nstep;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(mapn[nx][i]!=0)
			{
				q[tail]=i;
				step[tail]=nstep+mapn[nx][i];
				vis[i]=1;
				tail++;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;	
	for(int i=1;i<=m;i++)
		cin>>w[i];
		
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>f[j]>>t[i];
			if(j>1)
			{
				for(int k=1;k<j;k++)
					mapn[f[k]][f[j]]=mapn[f[j]][f[k]]=t[j]+t[k];
			}
		}
	}
	for(int i=1;i<=p;i++)
		cin>>x[i]>>y[i];
	if(m>20000)return cout<<w[x[p]]+w[y[p]],0;
	while(p--)
	{
		search();
		cout<<minn+w[x[p]]+w[y[p]]<<endl;
	}
	return 0;
}
