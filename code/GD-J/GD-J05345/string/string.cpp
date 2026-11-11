#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int x[maxn];
using ll = long long;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,ans=0,l=0,o=0,p=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>s[i];
		l+=x[i];	
	}
	ll len = s.size();
	for(int i=0;i<n;i++)
	{
		if(l/2<=p)
		{
			o = i;
			break;
		}
		p += x[i];
	}
	for(int i=0;i<o;i++)
	{
		
		if(s[i]==s[len-1-i]&&x[i]==x[len-i-1])
		{
			continue;
		}
		else if(s[i]!=s[len-i-1]&&x[i]==x[len-i-1])
		{
			ans+=x[i];
			s[i] = s[len-i-1];
			continue;
		}
		else if(s[i]==s[len-1-i]&&x[i]!=x[len-i-1])
		{
			if(x[i]>x[len-i-1])
			{
				x[len-i-2] -= x[i] - x[len-i-1];
				ans+= x[i] - x[len-i-1];
				continue;
			}
			if(x[i]<x[len-i-1])
			{
				x[i+1] = x[len-i-1] - x[i];
				ans+=x[len-i-1] - x[i];
				continue;
			}			
		}
		else
		{
			if(x[i]>x[len-i-1])
			{
				x[i] -= x[len-i-1];
				ans += x[i] - x[len-i-1];
				s[len-i-1] = s[i];
				continue;
			}
			if(x[i]<x[len-i-1])
			{
				x[len-i-1] -= x[i];
				ans +=  x[len-i-1] - x[i];
				s[i] = s[len-i-1];
				continue;
			}		
		}
	}
	cout<<ans;

	return 0;
}
