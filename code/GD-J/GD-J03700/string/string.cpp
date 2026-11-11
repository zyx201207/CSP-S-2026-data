#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct ch{
	char c;
	ll num;
}s[200005];
ll n;
ll ans;
char m;
ll ln,rn; 
int main()
{
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>s[i].num>>s[i].c;
	}
	for(ll l=1,r=n;l<r;l++,r--)
	{
		ln+=s[l].num;
		rn+=s[r].num;
		if(s[l].c!=s[r].c)
		{
			if(s[l].num>s[r].num)
			{
				ans+=s[l].num;
				s[r].c==s[l].c;
				s[r-1].num-=s[l].num-s[r].num;
			}
			else
			{
				ans+=s[r].num;
				s[l].c==s[r].c;
				s[l+1].num-=s[r].num-s[l].num;
			}
		}
	}
	if(s[n%2].c==1)
	{
		if(ln!=rn)ans++;
	}
	cout<<ans;
	return 0;
}
/*
6
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b
*/
