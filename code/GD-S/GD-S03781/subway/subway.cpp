#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,l,r,sum=0,w[500005],k[505],a[505][500005],t[505][500005];
vector<pair<int,int>> vec[500005];
vector<int> x[500005];
void dijstra(int x,int sum1,int q,int mu)
{
	if(x==mu)
	{
		sum=sum1;
		return;
	}
	int f,minn=INT_MAX;
	for(auto it:vec[x])
	{
		if(it.second<=minn&&it.first!=q)
		{
			minn=it.second;
			f=it.first;
		}
	}
	dijstra(f,sum1+minn,x,mu);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			x[j].push_back(i);
		}
		for(int j=2;j<=k[i];j++)
		{
			for(auto it:x[j])
			{
				for(auto is:x[j-1])
				{
					if(it==is)
					{
						vec[j].push_back({j-1,0});
			            vec[j-1].push_back({j,0});
					}
					else
					{
						vec[j].push_back({j-1,t[i][j]+t[i][j-1]});
			            vec[j-1].push_back({j,t[i][j-1]+t[i][j]});
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		sum+=w[l];
		sum+=w[r];
		dijstra(l,0,l,r);
		cout<<sum<<endl;
	}
	return 0; 
} 
