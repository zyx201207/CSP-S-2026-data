//GZ-J00148，任润淏，贵阳市第三实验中学
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, a[200005];
	string s[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		
	}
	if(n==1)
	{
		cout<<0;
	}
	if(s[1]==s[2])
	{
		cout<<0;
	}	
	else
	{
		cout<<min(a[1],a[2]);
	}	
	return 0;
}
