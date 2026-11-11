#include<bits/stdc++.h>
#define N 2000005
using namespace std;
long long c,t,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		long long s=x[2]-x[1];
		if(d<s) {cout<<"0\n";
		}
		cout<<n-d/s-1<<"\n";
	}
	return 0;
}
