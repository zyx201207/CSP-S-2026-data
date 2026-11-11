#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,d,a[2000005],f[2000005],s[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int x,num=n+1;
		x=a[2]-a[1];
		for(int i=4;i<=n;i+=2)
			if(i/2*x<=d&&(i-1)*x>d)
			{
				num=i;
				break;
			}
		cout<<n-num+1<<"\n";
	}
	return 0;
} 
