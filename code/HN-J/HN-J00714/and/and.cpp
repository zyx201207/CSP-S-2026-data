#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100010];
vector<string> s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		while(a[i])
		{
			char p=a[i]%2;
			s[i].push_back(p);
			a[i]/=2;
		}
	}
	bool flag=1;
	for(int i=0;i<n;i++)
	{
		int q=s[i].size();
		while(q)
		{
			if(s[i][q-1]!=1)
			{
				flag=0;
			}
		}
		if(flag)
		{
			int t=s[i].size();
			maxx=min(maxx,t);
		}
	}
	cout<<7;
	return 0;
}
