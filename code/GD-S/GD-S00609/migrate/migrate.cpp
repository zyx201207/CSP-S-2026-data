#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c;
	cin>>t;
	while(t--)
	{
		long long n,d,a[2000005]={},b[2000005]={};
		cin>>n>>d;
		cin>>a[1];
		for(int i=2;i<=n;i++)
		{
			cin>>a[i];
			b[i-1]=a[i]-a[i-1];
		}
		long long s=0;
		if(d<b[1]||d==b[1])
		{
			s=0;
		}
		else
		{
			s=n-(d/b[1])*2+1;
			if(s<0)
			{
				s=0;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
