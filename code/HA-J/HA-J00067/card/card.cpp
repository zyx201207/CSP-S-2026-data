#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
bool sorted(vector<int>&num)
{
	for(int i=1; i<num.size(); i++)
	{
		if(num[i]<num[i-1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;

	cin >> n >> m;
	vector<int> num(n);
	vector<int> pr(n+5);
	vector<int> hs(m+5);
	for(int i=0; i<n; i++)
	{
		cin >> num[i];
		if(mp[num[i]]!=0)
		{
			pr[mp[num[i]]-1]=i;
		}
		mp[num[i]] = i+1;
	}
	if(sorted(num))
	{
		for(int i=0; i<n; i++)
		{
			hs[num[i]]=i+1;
		}
		for(int i=0; i<m; i++)
		{
			cout << hs[i+1] << " ";
		}
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			vector<bool> vis(n);
			for(int j=i; j<n; j++)
			{

				if(vis[num[j]]==0)
				{
					hs[num[j]]++;
					vis[num[j]]=1;
				}
				while(pr[j]!=0)
				{
					j=pr[j];
				}
			}
		}
		for(int i=0; i<m; i++)
		{
			cout << hs[i+1] << " ";
		}
	}
	return 0;
}