#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,m,a[500005],cnt[300005],k[300005],d[300005],v;
vector<int> s;
int main()
{
	freopen('card.in','r',stdin);
	freopen('card.out','w',stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int u=1;u<=m;u++)
		{
			k[u]=0;
			cnt[u]=0;
		}
		for(int j=i;j<=n;j++)
		{
			s.push_back(a[j]);
			cnt[a[j]]++;
			if(cnt[a[j]]>1)
			{
				s.pop_back();
				while(s.back()!=a[j])
				{
					cnt[s.back()]--;
					s.pop_back();
				}
				cnt[a[j]]=1;
			}
		}
		v=s.size()-1;
		while(!s.empty())
		{
			k[s[v]]=1;
			v--;
			s.pop_back();
		}
		for(int i=1;i<=m;i++)
		{
			if(k[i])
			{
				d[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
}
