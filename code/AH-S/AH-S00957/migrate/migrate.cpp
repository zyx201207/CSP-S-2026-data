#include<bits/stdc++.h>
using namespace std;
int a[3000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long s=0,c,t,n,d;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
		cout<<s/2<<endl;
		cout<<0;
	}
	return 0;
}
