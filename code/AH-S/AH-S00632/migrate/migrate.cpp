#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
int c,t;
int n,d;
int a[N];
signed main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c==0||c==11||c==12)
		{
			int data=a[2]-a[1];
			if(d<2*data)
			{
				cout<<0<<endl;
				continue;
			}
			int cnt=d/data+1;
			cout<<n-cnt<<endl;
		}
	}
	
return 0;
}
