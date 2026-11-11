#include<bits/stdc++.h>
using namespace std;
long long n,h,ans,ha,a[200005],t,anss;
char c[200005];
bool ok,f;
string s,ss;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		ans+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		s=s+c[i];
	}
	t=s.size()-1;
	for(int i=1;i<=ans/2;i++)
	{
		if(s[h]!=s[t])anss++;
		t--;h++;
	}
	cout<<anss;
	return 0;
}
