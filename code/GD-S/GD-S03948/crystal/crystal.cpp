#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],b[500005],yb=1,ok=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	while(1)
	{
		m-=(b[yb]*yb);
		if(m<0)break;
		ok++;
		yb++;
	}
	cout<<ok;
	return 0;
 } 
