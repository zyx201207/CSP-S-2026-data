#include<bits/stdc++.h>
#define N 500005
using namespace std;
using ll=long long;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n;
ll m,a[N],s[N];
bool check(int x)
{
	ll mn=2e18;
	for(int l=1,r=x;r<=n;l++,r++) mn=min(mn,a[r]*x-(s[r]-s[l-1]));
	return mn<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}

