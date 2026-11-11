#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,l,r;
struct node
{
	long long s;
	char c;
}a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].s);
		cin>>a[i].c;
	}
	l=1,r=n;
	while(l<r)
	{
		if(a[l].c!=a[r].c)
		{
			if(a[l].s>a[r].s)ans+=a[r].s,a[l].s-=a[r].s,r--;
			else if(a[l].s<a[r].s)ans+=a[l].s,a[r].s-=a[l].s,l++;
			else ans+=a[l].s,l++,r--;
		}
		else
		{
			if(a[l].s>a[r].s)a[l].s-=a[r].s,r--;
			else if(a[l].s<a[r].s)a[r].s-=a[l].s,l++;
			else r--,l++;
		}
	}
	printf("%lld",ans);
	return 0;
}
