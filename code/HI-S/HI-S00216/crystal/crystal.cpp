#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,ans=1,s,y;
	double x,mi=INT_MAX;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x+=a[i];
	}
	x/=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i]-x)<=mi)
		{
			mi=abs(a[i]*1.0-x*1.0);
			y=i;
		}
	}
	for(int i=1;i<=y;i++)
	{
		if(m){
			while(a[i]!=s)
			{
				a[i]++;
				m--;	
			}
		}
	 }
	 for(int i=2;i<=n;i++)
	 {
	 	if(a[i]!=a[i-1])
	 	{
	 		break;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
