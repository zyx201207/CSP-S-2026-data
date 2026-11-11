#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,len,l,r,ans,i,sum;
ll a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		getchar();
		scanf("%c",&c[i]);
		len+=a[i];
	}
	if(len%2==1) 
	{
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(sum>=len/2+1) 
			{
				a[i]--;
				break;
			}
		}
	}
	l=1,r=n;
	while(l<r)
	{
		int cnt=0;
		if(a[l]<a[r]) 
		{
			for(i=l;i<=n;i++)
			{
				int x=min(a[r]-cnt,a[i]);
				if(c[i]!=c[r]) ans+=x;
				cnt+=x;
				a[i]-=x;
				if(cnt==a[r]) break;
			}
			l=i,r--;
			
		}
		else if(a[l]>a[r])
		{
			for(i=r;i>=1;i--)
			{
				int x=min(a[l]-cnt,a[i]); 
				if(c[i]!=c[l]) ans+=x;
				cnt+=x;
				a[i]-=x;
				if(cnt==a[l]) break;
			}
			r=i,l++;
		}
		else 
		{
			if(c[l]!=c[r]) ans+=a[l];
			l++,r--; 
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	printf("%lld",ans);
	return 0;
}
/*
3
2 a
2 b
1 c
*/
