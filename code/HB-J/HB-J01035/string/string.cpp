#include<bits/stdc++.h>
using namespace std;
string s = "";
int n,ans,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		int ai;
		char ci;
		cin>>ai>>ci;
		for(int j = 1;j <= ai;j++)
		{
			s+=ci;
		}
		cnt+=ai;
	}
	int l = 0,r = cnt-1;
	while(l < r)
	{
		if(s[l] != s[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
//RP++
