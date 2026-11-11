# include <bits/stdc++.h>
using namespace std;
int n;
string s=" ";
long long ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
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
			s+=c;
		}
	}
	long long len=s.size()-1;
	for(long long i=1;i<=len/2;i++)
	{
		if(s[i]!=s[len-i+1]) ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
