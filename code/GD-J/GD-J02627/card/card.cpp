#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
map<int,int> np;
int main()
{
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		string s="";
		for(int j=i;j<=n;j++)
		{
			if(s.find(a[j]+'0')==string::npos)
			{
				s+=a[j]+'0';
			}else
			{
				s=s.substr(0,s.find(a[j]+'0')+1);
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(s.find(j+'0')!=string::npos)
			{
				np[j]++;
			}
		}
	}
	for(auto i:np)
	{
		cout<<i.second<<' ';
	}
	return 0;
} 
