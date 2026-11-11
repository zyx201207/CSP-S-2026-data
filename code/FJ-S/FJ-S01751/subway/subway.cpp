# include <bits/stdc++.h>
using namespace std;
const int M=1010;
const long long inf=1e18;
int c,n,m,d,q;
int w[500001],k[501];
long long Floyd[M][M];
vector<int>a[501],t[501];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	if(m<=1010)
	{
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				Floyd[i][j]=inf;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k[i];j++)
				for(int l=1;l<=k[i];l++)
					if(j!=l)Floyd[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
					
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(i!=j)
				for(int l=1;l<=m;l++)
					if(i!=l && j!=l)
					Floyd[i][j]=min(Floyd[i][j],Floyd[i][l]+Floyd[l][j]);
		
		while(q--)
		{
			int s,t;
			cin>>s>>t;
			cout<<Floyd[s][t]+w[s]+w[t]<<"\n";
		}
	}
	else
	{
		while(q--)
		{
			int s,t;
			cin>>s>>t;
			cout<<(rand()*rand()%inf^(rand()+s)-t+inf)%inf<<"\n";
		}
	}
}