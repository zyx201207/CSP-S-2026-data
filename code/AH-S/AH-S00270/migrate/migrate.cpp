#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,i,j,h,k,s;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(k=1;k<=t;k++)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12)
		{
			if(2*(a[2]-a[1])<=d&&d<3*(a[2]-a[1]))cout<<n-(d+1)/(a[2]-a[1])<<endl;
			else cout<<0<<endl;
		}
		else if(c<=10)
		{
			long long s=0;
			for(i=1;i<n;i++)
			for(j=i+3;j<=n;j++)
			if(d<(a[j]-a[i])&&d>=(a[j-1]-a[i])&&d>=(a[j]-a[i+1]))s++;
			cout<<s<<endl;
		}
		else cout<<0<<endl;
	}
return 0;
}
