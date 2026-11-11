#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int cha=a[2]-a[1];
		if(cha>2*d)//zhi neng yi ci fei yi zuo
		{
			cout<<0<<'\n';
			continue;
		}
		int mx=d/cha;//zui duo yi ci fei ji zuo
		int len=mx+mx;
		if(len>n)
			cout<<0<<'\n';
		else
			cout<<n-len+1<<'\n';
	}
	return 0;
}
