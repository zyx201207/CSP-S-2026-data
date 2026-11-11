//GZ-S00305
//贵阳市白云区华师一学校
//廖博亚
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=2e6+5;
int a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,m;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(m>=2*(a[2]-a[1])&&m<3(a[2]-a[1]))
		{
			cout<<n-3<<endl;
		}
		else cout<<0<<endl;
	}

}
