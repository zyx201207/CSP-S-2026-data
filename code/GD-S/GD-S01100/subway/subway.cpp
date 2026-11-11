#include<bits/stdc++.h>
const int N=5e5+10;
const int K=5e2+10;
using namespace std;
int c,n,m,d,q;
long long w[N],k[N];//a[i][j]表示i地铁站的第j个线路有a[i][j]号线，t[i][j]表示第i个地铁站到第j条线路的时间，k[i]表示i地铁站的线路数 
long long f[K][K];
vector<int> a[N];
vector<int> t[N];
void init()
{
	for(int i=1;i<=n;i++)
	{
		int kk,xxx,yyy;
		cin>>kk;
		for(int j=1;j<=kk;j++)
		{
			cin>>xxx>>yyy;
			k[xxx]++;
			a[xxx].push_back(i);
			t[xxx].push_back(yyy);
		}
	}
}
int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			f[i][j]=1e17;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j1=0;j1<k[i];j1++)
		{
			for(int j2=0;j2<j1;j2++) f[a[i][j1]][a[i][j2]]=f[a[i][j2]][a[i][j1]]=t[i][j1]+t[i][j2];
		}
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
			}
		}
	}
	while(q--)
	{
		int st,ed;
		long long mi=1e17;
		cin>>st>>ed;
		for(int i=0;i<k[st];i++)
		{
			for(int j=0;j<k[ed];j++) mi=min(mi,f[a[st][i]][a[ed][j]]+t[st][i]+t[ed][j]);
		}
		cout<<mi+w[st]+w[ed]<<"\n";
	}
	return 0;
}
