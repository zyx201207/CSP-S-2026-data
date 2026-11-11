#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,sum;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		sum=0;
		cin>>n>>d;
		for(int j=0;j<n;j++)
			cin>>a[j];
		cout<<n/2-1<<endl;
	}
	return 0;
}
