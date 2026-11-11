#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,a[N],ans;
char c[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)s.push_back(c[i]);
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
