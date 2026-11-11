#include<bits/stdc++.h>
#define maxn 200010
#define ll long long 
using namespace std;
int a[maxn],n,A[maxn],T1,T2,t[28],T;
char c[maxn],p;
ll ans,L;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %c",&a[i],&c[i]);
		t[c[i]-'a'+1]++;
	}
	for(int i=1;i<=n;++i)
	{
			if(i==n-i+1) break;
			a[i]=a[i+T1];
			a[n-i+1]=a[n-i+1-T2];
			c[i]=c[i+T1];
			c[n-i+1]=c[n-i+1-T2];
		if(c[i]!=c[n-i+1])
		{	
			if(a[i]!=a[n-i+1]) 
			{
				if(a[i]<a[n-i+1])
				{
					a[n-i+1]-=a[i];
					ans+=a[i];
					a[i]=a[i+1];
					c[i]==c[i+1];
					T1++; i--;
				}
				if(a[i]>a[n-i+1])
				{
					a[i]-=a[n-i+1];
					ans+=a[n-i+1];
					a[n-i+1]=a[n-1];
					c[n-i+1]=c[n-1];
					T2++; i--;
				}
			}
			if(a[i]==a[n-i+1]) ans+=a[i];
		}
		if(c[i]==c[n+i-1])
		{
			if(a[i]<a[n-i+1])
			{
				a[n-i+1]-=a[i];
				a[i]=a[i+1];
				T1++; i--;
			}
			if(a[i]>a[n-i+1])
			{
				a[i]-=a[n-i+1];
				a[n-i+1]=a[n-1];
				T2++; i--;
			}
		} 
	}
	for(int i=1;i<=27;++i)
		if(t[i]>=T)
		{
			T=t[i];
			p=i+'a'-1;
		}
	for(int i=1;i<=n;++i) if(c[i]==p) L+=a[i];
	printf("%lld",min(ans,L));
	return 0;
}
