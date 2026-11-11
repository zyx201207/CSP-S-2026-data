#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,t,c=1,ans,a[5000005],b[5000005],f[5000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s.find(a[j]))
			{
				s.push_back(a[j]);
			}
			else
			{
				s.erase(s.find(a[j]),s.size()-1);
				s.push_back(a[j]);
			}
		}
		int y=s.size();
		for(int j=1;j<=y;j++)
		{
			int t=s[j];
			f[t]++;
		}
		s.erase(0,s.size());
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]+1<<" ";
	}
	return 0;
}
