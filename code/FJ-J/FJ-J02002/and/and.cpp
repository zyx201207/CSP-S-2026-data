#include<bits/stdc++.h>
using namespace std;
struct q
{
	long long sz;
	int zs;
}a[200005];
int z[100];
bool cmp(q x,q y)
{
	return x.zs>y.zs;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].sz;
		long long v=a[i].sz;
		int j=0;
		while(pow(2,j)<v)
		{
			j++;
		}
		a[i].zs=j-1;
	}
	sort(a,a+n,cmp);
	int p=0;
	int maxx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		z[a[i].zs]++;
		if(z[a[i].zs]>maxx)
		{
			maxx=z[a[i].zs];
			p=a[i].zs;
		}
	}
	long long q=-1;
	bool zz=true;
	int o=0;
	for(int i=0;i<n,o<m;i++)
	{
		if(a[i].zs<=p)
		{
			o++;
			if(q==-1)
			{
				q=a[i].sz;
			}
			else
			{
				q=(q&a[i].sz);
			}
		}
	}
	cout<<q;
	return 0;
}
