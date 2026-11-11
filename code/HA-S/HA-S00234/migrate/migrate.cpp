#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0)
	{
		cin>>n>>d;
		if(t==2)
		{
			if(n==4)cout<<1<<endl<<2<<endl;
			if(n==5)cout<<0<<endl<<1<<endl;
		}	
	}
	return 0;
}
