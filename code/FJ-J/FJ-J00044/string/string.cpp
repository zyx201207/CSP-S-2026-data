#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long ans;
int n,a[N];
char s[N];
string s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>s[i];
		for(int j=1; j<=a[i]; j++)
		{
			s1+=s[i];
		}
	}
	for(int i=0; i<s1.size()/2; i++)
	{
		if(s1[i]!=s1[s1.size()-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
