#include<bits/stdc++.h> 
using namespace std;
pair<int,char>a[200002];
vector<pair<int,char>>b;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,gcd;
	long long ans=0;
	cin>>n>>a[0].first>>a[0].second;
	gcd=a[0].first;
	for(int i=1;i<n;i++)
		cin>>a[i].first>>a[i].second,
		gcd=__gcd(gcd,a[i].first);
	if(gcd<3)
	{
		for(int i=0;i<n;i++)
			s.append(string(a[i].first,a[i].second));
		for(int i=0,j=s.size()-1;i<j;i++,j--)
			ans+=(s[i]!=s[j]);
		cout<<ans;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			const int asc=a[i].second;
			for(int j=a[i].first/gcd;j;j--)
				b.push_back({gcd,asc});
		}
		for(int i=0,j=b.size()-1;i<j;i++,j--)
			ans+=(b[i].second!=b[j].second);
		cout<<ans*gcd;
	}
	return 0;
}
