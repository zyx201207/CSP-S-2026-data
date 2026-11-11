#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
ll n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)
		{
			s=s+c;
		}
	}
	ll i=0,j=s.size()-1;
	while(i<=j)
	{
		if(s[i]!=s[j])
		{
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans;
	return 0;
}

