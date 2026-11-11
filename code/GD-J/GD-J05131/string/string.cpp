#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct str
{
	ll a;
	char c;
}s[200005];
ll n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
	}
	int l=1,r=n;
	while(l<r)
	{
		if(s[l].c!=s[r].c)
		{
			ans+=min(s[l].a,s[r].a);
		}
		ll ko=min(s[l].a,s[r].a);
		s[l].a-=ko;
		s[r].a-=ko;
		if(s[l].a==0)
		{
			l++;
		}
		if(s[r].a==0)
		{
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
2 a
2 b
2 c

*/
