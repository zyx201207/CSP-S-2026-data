#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int ans;
long long c;
long long a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	int x;
	char y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		a+=x;
		for(int j=1;j<=x;j++)
		{
			s=s+y;
		}
	}
	while(s.size()>0)
	{

		if(s[c]!=s[a-1])ans++;
		a--;
		c++;
		s.size()-2;
	}
	cout<<ans;
	return 0;
}
