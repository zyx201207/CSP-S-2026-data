#include<bits/stdc++.h>
using namespace std;
int n,a[200005];char c[200005];long long s,nl,nr,ns,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	nl=1,nr=n;
	while(nl<nr)
	{
		if(a[nl]>a[nr])
		{
			if(c[nl]!=c[nr])cnt+=a[nr];
			a[nl]-=a[nr];
			nr--;
		}
		else if(a[nl]<a[nr])
		{
			if(c[nl]!=c[nr])cnt+=a[nl];
			a[nr]-=a[nl];
			nl++;
		}
		else
		{
			if(c[nl]!=c[nr])cnt+=a[nl];
			nl++;
			nr--;
		}
	}
	cout<<cnt;
	return 0;
}
