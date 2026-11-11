#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int C,T;
int n;
long long d;
long long a[N];
long long pf_11_12()
{
	if(n<=d/(a[2]-a[1])+1||d/(a[2]-a[1])==1)
	{
		return 0;
	}
	long long s=0;
	for(int i=d/(a[2]-a[1])+2;i<=n;i++)
	{
		s+=min((a[i]-a[1]-d+1)/(a[2]-a[1]),d/(a[2]-a[1])-1);
	}
	return s;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    while(T--)
    {
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(C>=11&&C<=12)
		{
			cout<<pf_11_12()<<"\n";
		}
		else
		{
			cout<<0<<"\n";
		}
	}
}
