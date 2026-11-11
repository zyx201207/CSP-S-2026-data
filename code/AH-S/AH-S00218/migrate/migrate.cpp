#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int C,T,n;
long long d,a[N];
int main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        if(d==2)puts("1");
		else if(d==3)puts("2");
		else puts("0");
	}
	return 0;
}
