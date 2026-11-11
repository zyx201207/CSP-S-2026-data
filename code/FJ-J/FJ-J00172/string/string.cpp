#include<bits/stdc++.h>
#define cs first
#define zm second
using namespace std;
int n;
pair<int,char>a[200078];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].cs>>a[i].zm;
	}
	long long as=0;
	int zz=1,yy=n;
	while(zz<yy)
	{
		if(a[zz].cs<a[yy].cs)
		{
			as+=a[zz].zm==a[yy].zm?0:a[zz].cs;
			a[yy].cs-=a[zz].cs;
			zz++;
		}
		else if(a[zz].cs>a[yy].cs)
		{
			as+=a[zz].zm==a[yy].zm?0:a[yy].cs;
			a[zz].cs-=a[yy].cs;
			yy--;
		}
		else
		{
			as+=a[zz].zm==a[yy].zm?0:a[zz].cs;
			zz++;
			yy--;
		}
	}
	cout<<as;
	return 0;
}
