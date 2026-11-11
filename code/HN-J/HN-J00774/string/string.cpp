#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,cnt;
string s;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char s1;
		cin>>a;
		cin>>s1;
		while(a--)
		s+=s1;
	}
	int len=s.size();
	for(int i=0;i<=(len/2);i++) 
	{
		if(len%2!=0)
		{
			if(s[i]==s[len-i-1])
			{
				continue;
			}
			else
			{
				cnt++;
			}
		}
		else
		{
			if(s[i]==s[len-i])
			{
				continue;
			}
			else
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

