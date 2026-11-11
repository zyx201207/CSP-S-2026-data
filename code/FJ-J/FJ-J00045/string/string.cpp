#include<bits/stdc++.h>
using namespace std;
long long a[200002];
char s[200002];
long long a2[200002];
char s2[200002];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin>>n;
	long long l=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		l+=a[i];
		a2[n-i+1]=a[i];
		s2[n-i+1]=s[i];
	}
	long long mid=(l+1)/2;
	long long ls=0,rs=0,rt=0,ri=1;
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		ls+=a[i];
		if(rt>=a[i]){
			rt-=a[i];
			if(s[i]!=s2[ri-1])
			ans+=a[i];
		}
		else
		{
			a[i]-=rt;
			if(i!=1&&s[i]!=s2[ri-1])
			{
				ans+=rt;
				rt=0;
			}
			while(rs+a2[ri]<ls){
				if(s[i]!=s2[ri])ans+=a2[ri];
				a[i]-=a2[ri];
				rs+=a2[ri];
				ri++;
			}
			if(s[i]!=s2[ri])ans+=a[i];
			rs+=a2[ri];
			rt=a2[ri]-a[i];
			ri++;
		}
	}
	cout<<ans/2;
	return 0;
}
