#include<bits/stdc++.h>
using namespace std;
char ch;
int n,a[200010];
char s[200010];
long long ans,len;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&ch);
		s[i]=ch;
		len+=a[i];
	}
	long long l=1,r=len;
	long long l2=1,r2=n;
	long long l1=a[l2],r1=a[r2];
	char chl=s[l2],chr=s[r2];
	while(l<=r)
	{
		if(chl!=chr)ans++;
		l++;
		r--;
		if(l>l1)
		{
			l2++;
			l1+=a[l2];
			chl=s[l2];
		}
		if(r<len-r1+1)
		{
			r2--;
			r1+=a[r2];
			chr=s[r2];
		}
	}
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
