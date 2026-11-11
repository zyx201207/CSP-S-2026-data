#include<bits/stdc++.h>
using namespace std;
int n,c,ans=0;
char a;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		cin>>a;
		for(int j=1;j<=c;j++)
		{
			s+=a;
		}
	}
	int m=s.size()/2;
	for(int i=1;i<=m;i++)
	{
		if(s[i]==s[s.size()-(i-1)])
		{
			continue ;
		}
		else
		{
				ans++;
		}
	}
	cout<<ans;
	return 0;
}
