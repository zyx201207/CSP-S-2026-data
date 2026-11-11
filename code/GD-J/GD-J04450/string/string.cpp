#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int sum,ans;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	for(int i=0;i<sum;i++)
	{
		if(s[i]!=s[sum-i])
		ans++;
	}
	if(sum%2) ans--;
	cout<<ans;
	return 0;
}

