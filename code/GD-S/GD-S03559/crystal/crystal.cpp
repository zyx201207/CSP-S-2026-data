#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt,ans;
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int l=1,r=0;l<=n;l++)
	{
		cnt-=a[r]-a[l-1];
		while(r<n&&cnt+(a[r+1]-a[r])*(r-l+1)<=m)
		{
			r++;
			cnt+=(a[r]-a[r-1])*(r-l);
		}
		ans=max(ans,r-l+1ll);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
