#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,ans,sum,l,r,a[200010];
char c[200010];
bool flag=1;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(a[i]>500)
		{
			flag=0;
		}
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			while(a[i]--)
			{
				s+=c[i];
			}
		}
		for(int i=0;i<=s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-i-1])
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(ll i=1,j=n;i<=j&&l<=sum/2&&r<=sum/2;)
	{
		if(c[i]!=c[j])
		{
			if(a[i]>a[j])
			{
				ans+=a[j];
				l+=a[j];
				r+=a[j];
				j--;
			}
			else if(a[i]<a[j])
			{
				ans+=a[i];
				l+=a[i];
				r+=a[i];
				i++;
			}
			else
			{
				ans+=a[i];
				l+=a[i];
				r+=a[i];
				i++;
				j--;
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				l+=a[j];
				r+=a[j];
				j--;
			}
			else if(a[i]<a[j])
			{
				l+=a[i];
				r+=a[i];
				i++;
			}
			else
			{
				l+=a[i];
				r+=a[i];
				i++;
				j--;
			}
		}
	}
	cout<<ans;

	return 0;
}
