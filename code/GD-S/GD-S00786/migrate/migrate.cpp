#include<bits/stdc++.h>
using namespace std;

long long a[2000010];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d;
		memset(a,0,sizeof a);
		cin>>n>>d;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int i;
		for(i=0;i<n;i++)
		{
			if(abs(a[i]-a[0])>d)
				break;
		}
		cout<<n-i<<endl;
	}
}
