#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,cost,num,k1,k2;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1;
	cost=0;
	num=0;
	for(int i=2;i<=n;i++)
	{
		k1=0;
		k2=(i-l)*(a[i]-a[i-1]);
		if(k2+cost<=m)
		{
			cost+=k2;
		}
		else
		{
			k1=a[i-1]-a[l];
			if(k2<k1)
			{
				l++;
				cost-=(k1-k2);
			}
			else
			{
				num=max(i-l,num);
				i=l;
				l++;
				cost=0;
			}
		}
	}
	cout<<num;
	return 0;
}
