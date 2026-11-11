#include<bits/stdc++.h>
using namespace std;
long long n,m,s[222222];
map<long long,long long>mp2;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		map<long long,bool>mp;
		map<long long,long long>mp1;
		queue<long long>q;
		for(int j=i;j<=n;j++)
		{
			if(mp[s[j]])
			{
				for(int k=mp1[s[j]]+1;k<=q.size();k++)
				{
					mp[q.back()]=0;
					q.pop();
				}
				//mp1[s[j]]++;
			}
			else 
			{
				mp[s[j]]=1;
				mp1[s[j]]=j;
				q.push(s[j]);
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(mp[j]&&mp2.count(j)) mp2[j]++;
			else if(mp[j]&&!mp2.count(j)) mp2[j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(mp2.count(i)) cout<<mp2[i]<<" ";
	}
	return 0;
}
//4 3
//1 2 1 3
