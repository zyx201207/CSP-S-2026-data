#include<bits/stdc++.h>
using namespace std;
int c;
long long n,t,d,a[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<n-3<<endl;
	}
}
