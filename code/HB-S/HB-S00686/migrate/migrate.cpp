#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e6+5;
int c,T;
int a[maxn],n,d;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11||c==12)
		{
			if(n<=3)
			{
				cout<<0<<"\n";
				continue;
			}
			int num=d/(a[2]-a[1]);
			if(num<2)
			{
				cout<<0<<"\n";
			}
			else
			{
				cout<<max(n-2*num+1,0ll)<<"\n";
			}
		}
	}
    return 0;
}
