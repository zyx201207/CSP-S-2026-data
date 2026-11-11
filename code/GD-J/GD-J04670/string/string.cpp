#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e5+5;
int n;
ll a[MAXN],s[MAXN],ans;
char c[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>c[i];
		s[i]=s[i-1]+a[i];
	}
	ll l=1,r=n,ls=a[1],rs=a[n];
	while(l<r)
	{
		if(ls>rs){
			if(c[l]!=c[r])
				ans+=min(a[r],rs-(ls-a[l]));
			r--;
			rs+=a[r];
		}
		else{
			if(c[l]!=c[r])
				ans+=min(a[l],ls-(rs-a[r]));
			if(ls<rs){
				l++;
				ls+=a[l];
			}
			else{
				l++;r--;
				ls+=a[l];
				rs+=a[r];
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
