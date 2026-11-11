#include<bits/stdc++.h>
using namespace std;
long long n,m,maxv=-1000000000000,sum;
long long a[500005];
int main(void)
{
	//crystal
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=1;
	//5 5
//1 2 4 8 9
	while(l<=r && r<=n)
	{
		while(r<=n)
		{
			if(sum+(a[r+1]-a[r])*(r-l+1)>m)break;
			sum=sum+(a[r+1]-a[r])*(r-l+1);
			r++;
		}
		maxv=max(maxv,r-l+1);
		l++;
		sum=sum-(a[r]-a[l]);
	}
	cout<<maxv;
	return 0;
}
