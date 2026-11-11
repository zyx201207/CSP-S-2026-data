#include<bits/stdc++.h>
using namespace std;
int m,n,x,b[200005];
long long z;
bool v[200005];
string e[200005];
int ans[30];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 	
	for(int i = 1;i<=n;i++)
	{
		string s;
		cin>>x;
		while(x)
		{
			s+=(x%2+'0');
			x/=2;
		}
		for(int j = 1;j<=30-s.size();j++)
		{
			e[i]+='0';
		}
		for(int j = s.size()-1;j>=0;j--)
		{
			e[i]+=s[j];
		}
	}
	sort(e+1,e+n+1,greater<string>());
	for(int i = 1;i<=29;i++)
	{
		ans[i]=1;
		int tot=0;
		for(int j = 1;j<=n;j++)
		{
			if(e[j][i]=='1'&&!v[j])
			{
				tot++;
			}
		}
		if(tot>m)
		{
			for(int j = 1;j<=n;j++)
			{
				if(e[j][i]=='0'&&!v[j])
				{
					v[j]=1;
				}
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		if(!v[i]&&m)
		{
			for(int j = 1;j<=29;j++)
			{
				ans[j]&=(e[i][j]-'0');
			}
			m--;	
		}
		
	}
	for(int i = 29;i>=1;i--)
	{
		z+=ans[i]*pow(2,30-i-1);
	}
	cout<<z;
	return 0;
}
