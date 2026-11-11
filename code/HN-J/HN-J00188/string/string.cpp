#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int E=2e5+5;
struct
{
	int a;
	char c;
}s[E];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	int l=1,r=n,ans=0;
	while(l<r)
	{
		if(s[l].c!=s[r].c)
		{
			if(s[l].a>s[r].a)
			{
				ans+=s[r].a;
				s[l].a-=s[r].a;
				r--;
				continue;
			}
			if(s[l].a<s[r].a)
			{
				ans+=s[l].a;
				s[r].a-=s[l].a;
				l++;
				continue;
			}
			if(s[l].a==s[r].a)
			{
				ans+=s[r].a;
				l++;
				r--;
				continue;
			}
		}
		if(s[l].c==s[r].c)
		{
			if(s[l].a>s[r].a)
			{
				r--;
				continue;
			}
			if(s[l].a<s[r].a)
			{
				l++;
				continue;
			}
			if(s[l].a==s[r].a)
			{
				l++;
				r--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}

