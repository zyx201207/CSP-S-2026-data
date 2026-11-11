#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long ans,n,a[200005];
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	int m=s.size();
	s=' '+s;
	for(int i=1;i<=m/2;i++)
	{
		if(s[i]!=s[m+1-i])
			ans++;
	}
	cout<<ans;
	return 0;
}
