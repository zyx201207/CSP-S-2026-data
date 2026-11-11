#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1000001];
int w2[100001][21];
int x[40001],y[40001];
void ff(int x)
{
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,ll;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int a,t;
			cin>>a>>t;
			w2[a][i]=t;
			if(i>1)
			{
				x[ll]=a;
				y[a]=ll;
			}
			ll=a;
		}
	}
	while(q--)
	{
		int xxx,yyy;
		cin>>xxx>>yyy;
		ff(xx);
	}
	return 0;
} 
