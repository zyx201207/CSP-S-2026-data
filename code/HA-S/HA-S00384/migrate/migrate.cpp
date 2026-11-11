#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
long long c,t,n,d;
long long a[1000000];
map<long long,bool> m;
bool check(long long id,long long d)
{
	return (m[id+(d*2-1)]&&m[id+d]&&m[id+d-1]);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		m.clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			m[a[i]]=1;
		}
		if(a[n]-a[1]<=d)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			long long id=a[i];
			while(id<=n)
			{
				if(check(id,d))ans++;
				id+=d;
				if(!m[id])break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


