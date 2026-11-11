#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500010];
vector<long long> a[510];
vector<long long> t[510];
vector<long long> b[500010];
long long bt[470010][510];
long long x;
long long y;
long long ans=1e18;
long long st1[510];
long long st2[500010];
void dfs(long long line,long long sta,long long sum)
{
	if(sta==y)
	{
		sum-=bt[sta][line];
		ans=min(ans,sum+w[sta]);
		return;
	}
	if(sum>ans)return;
	st1[line]=1;
	st2[sta]=1;
	for(int i=0;i<a[line].size();i++)
	{
		long long next_sta=a[line][i];
		if(st2[next_sta])continue;
		for(int j=0;j<b[next_sta].size();j++)
		{
			long long next_line=b[next_sta][j];
			if(st1[next_line])continue;
			cout<<line<<" "<<sta<<" "<<next_line<<" "<<next_sta<<endl;
			dfs(next_line,next_sta,sum+t[line][i]+bt[next_sta][next_line]);
		}
	}
	st1[line]=0;
	st2[sta]=0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);         //¼ÇµÃÉ¾×¢ÊÍ 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long an;
		cin>>an;
		for(int j=1;j<=an;j++)
		{
			long long A,T;
			cin>>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
			b[A].push_back(i);
			bt[A][i]=T;
		}
	}
	while(q--)
	{
		cin>>x>>y;
		for(long long i=1;i<=n;i++)st1[i]=0;
		for(long long i=1;i<=m;i++)st2[i]=0;
		ans=0;
		for(long long i=0;i<b[x].size();i++)
		{
			cout<<x<<" "<<b[x][i]<<endl;
			dfs(b[x][i],x,w[x]+bt[x][b[x][i]]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
