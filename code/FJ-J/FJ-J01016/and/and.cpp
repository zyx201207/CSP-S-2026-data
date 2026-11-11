#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n],o[n];
	string l[n];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		o[i]=s[i];
	}
	sort(s+1,s+n+1);
	cout<<s[n-1];
	return 0;
}
