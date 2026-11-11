#include<bits/stdc++.h>
using namespace std;
long long a[200100]={0};
char b[200100]={0};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	long long p=1,q=n;
	long long ans=0;
	while(p<q)
	{
		if(a[p]<a[q])
		{
			if(b[p]!=b[q]) ans+=a[p];
			a[q]-=a[p];
			a[p]=0;
			p++;
		}
		if(a[p]>a[q])
		{
			if(b[p]!=b[q]) ans+=a[q];
			a[p]-=a[q];
			a[q]=0;
			q--;
		}
		if(a[p]==a[q])
		{
			if(b[p]!=b[q]) ans+=a[p];
			a[p]=0,a[q]=0;
			p++,q--;
		}
	}
	printf("%lld",ans);
	return 0;
}
