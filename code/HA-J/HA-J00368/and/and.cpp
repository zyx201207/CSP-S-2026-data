#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a,c=-9999,e;
	long long b[200001];
	cin>>n>>m;
	for(a=1;a<=n;a++)
		cin>>b[a];
	if(m==1)
	{
		for(a=1;a<=n;a++)
		if(c<b[a])
			c=b[a];
		cout<<c;
	}
	if(m==n)
	{
		c=b[1];
		for(a=2;a<=n;a++)
			c=c&b[a];
		cout<<c;
	}
	if(m==2)
	{
		for(a=1;a<2000;a++)
			for(e=a+1;e<=2000;e++)
				if(c<(b[a]&b[e]))
					c=(b[a]&b[e]);
		cout<<c;
	}
	return 0;
}