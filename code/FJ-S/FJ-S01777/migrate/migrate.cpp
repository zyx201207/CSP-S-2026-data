#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;long long d;
long long a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
		scanf("%lld",&a[i]);	
		}
		long long cd=a[2]-a[1];
		if(d<=cd)
		printf("0\n");
		else
		{
			long long k=1ll*2*d/cd-1;
			cout<<fmax(n-k,0)<<endl;
		}
	}
}
