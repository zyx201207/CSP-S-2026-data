#include<bits/stdc++.h>
#define int long long
using namespace std;
string s=" ";
int n,ans,len;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)
		{
			s+=c;
		}
		len+=x;
	}
	int m=len/2;
	if(len%2==0)
	{
		for(int i=1;i<=m;i++)
		{
			
			if(s[i]!=s[len-i+1])
			{
				ans++;
			}       
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			
			if(s[i]!=s[len-i+1])
			{
				ans++;
			}  
		}
	}
	cout<<ans;
	return 0;
}
// 4 6;
       