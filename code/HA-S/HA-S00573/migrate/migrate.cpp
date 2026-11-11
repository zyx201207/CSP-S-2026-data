#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000100;
ll c,t,n,d,a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(c==11||c==12)
		{
			ll k=d/(a[2]-a[1]);
			ll sum=0;
			for(int i=1;i<k;i++) sum+=n-k-1;
			printf("%lld",sum);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
