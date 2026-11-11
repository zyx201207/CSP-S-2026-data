#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long s[maxn],e[maxn];
char c[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long n;
	cin>>n;
	long long x;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c[i];
		if(i==1)s[i]=1;
		else s[i]=e[i-1]+1;
		e[i]=s[i]+x-1;
	}
	long long l=1,r=n;
	long long ans=0;
	while(l<=r)
	{
		long long l1=e[l]-s[l]+1,l2=e[r]-s[r]+1;
		if(l1<l2)
		{
			if(c[l]!=c[r])ans+=l1;
			l++;
			e[r]-=l1;
		}
		else if(l1>l2)
		{
			if(c[l]!=c[r])ans+=l2;
			r--;
			s[l]+=l2;
		}
		else
		{
			if(c[l]!=c[r])ans+=l2;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

