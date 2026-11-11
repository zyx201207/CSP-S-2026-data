#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,h,t;
LL a[200005],gs,use,ans,s1[200005],s2[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s1[i]=s1[i-1]+a[i];
		cin >> c[i];
	}
	for(int i=n;i>=1;i--) s2[i]=s2[i+1]+a[i];
	h=1,t=n;
	gs=0;
	while(h<t)
	{
		use=gs;
		gs=s1[h];
		while(h<t&&s2[t]<=gs)
		{
			if(c[h]!=c[t])
			{
				ans+=s2[t]-use;
			}
			use=s2[t];
			t--;
		}
		if(c[h]!=c[t])
		ans+=gs-use;
		h++;
	}
	printf("%lld",ans);
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
