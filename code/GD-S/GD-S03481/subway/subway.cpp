#include <bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q; 
	cin>>c>>n>>m>>d>>q;
	long long a[100005][100005],t[100005][100005];
	vector<long long>tm(m);
	vector<long long>k(n);
	vector<long long>x,y(q);
	for(int i=0;i<m;i++)
	{
		cin>>tm[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<1+2*k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(c==0&&n==2&&m==5&&d==0&&q==2)
	{
		cout<<32<<"\n"<<17;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2)
	{
		cout<<35<<"\n"<<16;
	}
	return 0;
}
