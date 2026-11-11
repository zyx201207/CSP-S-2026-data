#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int c[500010];
bool cmp(int x,int y)
{
	return x>y
}
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
	for(int i=1,i<=n,i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int o=1,o<=n-1,o++)
	{
		b[o]=a[o]-a[o+1];
		c[o]=a[1]-a[o+1];
		for(int o=1,o<=n-1,o++)
		{
			int cnt=cnt+c[o];
			if(cnt=m)
			{
				cout<<o;
			}
		}
	}
	return 0;
}
