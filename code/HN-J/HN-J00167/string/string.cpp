#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5;
int n;
int a[N];
char c[N];
int len;
vector<int> r;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int last_r=1;
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		cin >> c[i];
		if(a[i]>500)
		{
			flag=true;
		}
		len+=a[i];
		r.push_back(last_r);
		last_r+=a[i]-1;
	}
	if(!flag)//yes! 68分！ 
	{
		string s="";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s+=c[i];
			}
		}
		int ans=0;
		s="#"+s;
		for(int i=1;i<=len/2;i++)
		{
			if(s[i]!=s[len+1-i])
			{
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	else
	{
		cout << 0; 
	}
	return 0;
}
/*
思路：
判断前半段是否跟后半段相同

*/
