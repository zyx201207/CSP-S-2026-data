#include<bits/stdc++.h>
using namespace std;
vector<int>a;
vector<int>an;
vector<int>mm;
vector<int>ms(200002,0);
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a.resize(n);
	an.resize(n);
	mm.resize(m);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		mm[i]=i;
	}
	int ll=n;
	while(ll--)
	{
		for(int i=0;i<an.size();i++)
		{
			a.push_back(an[i]);
			an.pop_back();
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mm[j]==a[i])
				{
					ms[i]++;
				}
			}
			for(int j=i+1;j<n;j++)
			{
				if(a[j]==a[i])
				{
					for(int k=0;k<j-i;k++)
					{
						an.push_back(a[k]);
						a.pop_back();
					}
				}
			}
			
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ms[i]<<" ";
	}
	return 0;
} 
