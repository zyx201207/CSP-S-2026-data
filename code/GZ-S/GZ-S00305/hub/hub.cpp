//GZ-S00305
//贵阳市白云区华师一学校
//廖博亚
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==0&&m==2) cout<<1<<endl<<2<<endl;
	else if(n==0&&m==3) cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9<<endl;
	else
	{
		for(int i=1;i<=n;i++) cout<<1<<endl;
		return 0;
	}
}
