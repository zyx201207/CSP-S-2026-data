#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5,inf=1e18;
ll n,s[N],ans;
string v[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>v[i];
	}
	for(ll i=1,j=n;;)
	{
		if(i>=j)
		{
			break;
		}
		if(v[i]!=v[j])
		{
			if(s[i]>s[j])
			{
				ans+=s[j];
				s[i]-=s[j];
				j--;
			}
			else
			{
				ans+=s[i];
				s[j]-=s[i];
				i++;
			}
		}
		else
		{
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}