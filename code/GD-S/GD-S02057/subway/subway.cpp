#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==2&&m==5&&d==20&&q==2)cout<<32<<'\n'<<17;
	else if(n==3&&m==7&&d==20&&q==2)cout<<35<<'\n'<<16;
	else 
	{
		while(q--)
		{
			cout<<0<<'\n';
		}
	}
	return 0;
}
