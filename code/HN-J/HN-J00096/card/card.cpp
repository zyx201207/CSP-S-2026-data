#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
int a[500005],t[300005],wz[500005];
bool v[300005];//t´ğ°¸£¬sÄ£Äâ 
vector<int>s;
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
		while(s.size()!=0)
		{
			s.pop_back();
		}
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]]==1) 
			{
				for(int i=wz[a[j]]+1;i<=s.size();i++)
				{
					v[s[i]]=0;
					s.pop_back();
				}
			}
			else
			{
				s.push_back(a[j]);
				v[a[j]]=1;
				wz[a[j]]=s[a[j]];
			}
		} 
		for(int i=1;i<=m;i++)
		{
			if(v[i]==1)
			{
				t[v[i]]++;
				v[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;	
} 
