#include <bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(nullptr);
using ll=long long;
const int N = 2e5+10;
int n,ans;
int a[N];
char c[N];
string s;
void solve()
{
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	int len=0;
	if(s.length()%2==0) len=s.length()/2;
	else len=(s.length()+1)/2;
	while(true)
	{
		flag=true;
		for(int i=0;i<len;i++)
		{
			if(s[i]!=s[s.length()-i-1])
			{
				s[s.length()-i-1]=char(s[i]);
				ans++;
				flag=false;
			}
		}
		if(flag)
		{
			cout<<ans;
			return ;
		}
	}
}
signed main()
{
	ios;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	solve();
	return 0;
}

