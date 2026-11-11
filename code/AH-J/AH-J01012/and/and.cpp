#include<bits/stdc++.h>
using namespace std;
long long n,m,t,x,a[200010],maxn=-1;
string s[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		while(t!=0)
		{
			t--;
			s[i][m]++;
			if(s[i][m]-'0'>=2)
			{
				for(int j=0;j<=m;j++)
					s[i][j]='0';
				m++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int h=0;h<max(s[j].size(),s[i].size());h++)
			{
				if(s[i][h]==s[j][h])a[i]++;
			}
		}
		if(a[i]>maxn)maxn=a[i];
	}
	cout<<maxn;
}
