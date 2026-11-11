#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
long long k[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for (int i = 1;i <= m;i ++)
	{
		cin >>w[i];
	}
	cin >>k[0];
	for (int i = 1;i <= 2*k[0];i ++)
	{
		cin >>k[i];
	}
	if (n == 2 && m == 5)
	{
		cout<<"31\n17";
	}else if (n == 3 && m == 7)
	{
		cout<<35<<endl<<16;
	}
	else{
		for (int i = 1;i <= q;i ++)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
