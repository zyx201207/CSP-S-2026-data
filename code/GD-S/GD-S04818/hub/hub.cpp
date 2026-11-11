#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&m,&n);
	for(int i=1;i<=n;i++)
	{
		cout<<rand()*m;
	}
	return 0;
}
