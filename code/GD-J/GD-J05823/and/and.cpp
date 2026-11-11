#include<bits/stdc++.h>
using namespace std;
int n,m,er[50];
string s[2009];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		cout<<x;
		return 0;
		while(x!=0)
		{
			int x1=x%2;
			s[i]=to_string(x1)+s[i];
			x/=2;
		}
	}
	er[0]=1;
	for(int i=1;i<=25;i++)
	{
		er[i]=er[i-1]*2;
	}
	sort(s+1,s+n+1,cmp);
	string ans;
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<=max(s[i].size(),s[i-1].size())-1;j++)
		{
			if(s[i][j]==s[i-1][j])
			{
				ans='1'+ans;
			}
		}
	}
	return 0;
/*
for(int i=2;i<=m;i++)
	{
		int ans=0;
		for(int j=s[i].size()-1;j>=0;j--)
		{
			string s1;
			s1+=s[i][j]
			int x=stoi(s1);
			ans+=x*er[j];
		}
	}
*/

}

