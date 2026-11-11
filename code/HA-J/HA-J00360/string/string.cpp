#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans=0,sum=0;
char s[1000000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll k=0;
	for(ll i=1;i<=n;i++)
	{
		ll a;
		char c;
		cin>>a>>c;
		sum+=a;
		while(a--)
		{
			k++;
			s[k]=c;
		}
	}
	for(int i=1;i<=sum/2;i++)
	{
		if(s[i]!=s[sum-i+1])ans++;
	}
	cout<<ans;
	return 0;
}
