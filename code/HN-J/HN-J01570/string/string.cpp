#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+11;
ll n,a[N];
char c[N];
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n); 
	for(int i=1;i<=n;++i)scanf("%lld %c",&a[i],&c[i]);
//	for(int i=1;i<=n;++i)printf("%lld %c\n",a[i],c[i]);
	ll l=1,r=n,ans=0;
	while(l<r)
	{
		while(a[l]>a[r])
		{
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			r--;			
		}
		if(l==r)break;
		if(c[l]!=c[r])ans+=a[l];
		a[r]-=a[l];
		l++;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
8:53 start
2
2 a
3 a

3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

9:02 end
so easy!
*/
