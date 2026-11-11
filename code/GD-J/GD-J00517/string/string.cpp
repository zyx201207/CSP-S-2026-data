#include <bits/stdc++.h>
using namespace std;
long long ll=0,rr=0,a=0,n=0,zs=0,ml=0,mr=0,mid=0,ans=0,l[212345]= {0},r[212345]= {0};
char c[212345];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l[0]=0,r[0]=0;
	for(long long i=1; i<=n; i++)
	{
		cin>>a;
		zs+=a;
		l[i]=r[i-1]+1;
		r[i]=l[i]+a-1;
		cin>>c[i];
	}
	if(zs<=1e8)
	{
		string s="";
		for(long long i=1; i<=n; i++)
		{
			for(int j=0; j<=(r[i]-l[i]); j++)
			{
				s+=c[i];
			}
		}
		for(int i=0;i*2<s.size();i++){
			if(s[i]!=s[s.size()-i-1]) ans++;
		}
	}
	else
	{
		for(long long i=1; i<=n; i++)
		{
			if(l[i]>(zs/2)) break;
			ll=1,rr=n;
			while(ll<=rr)
			{
				mid=(ll+rr)/2;
				if(r[mid]>=zs-l[i]+1)
				{
					mr=mid;
					rr=mid-1;
				}
				else
				{
					ll=mid+1;
				}
			}

			ll=1,rr=n;
			while(ll<=rr)
			{
				mid=(ll+rr)/2;
				if(l[mid]<=zs-r[i]+1)
				{
					ml=mid;
					ll=mid+1;
				}
				else
				{
					rr=mid-1;
				}
			}
			for(int j=mr; j>=ml; j--)
			{
				if(c[j]==c[i]) continue;
				else ans+=min(r[i]-l[i],r[j]-l[j])+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
