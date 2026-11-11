#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>num(m+1);
	vector<pair<int,bool>>vec(n+10);
	for(int i=1;i<=n;i++)
		cin>>vec[i].first;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int flag=0;
			for(int k=j+1;k<=n;k++)
				if(vec[j].first==vec[k].first)
				{
					flag=k;
					break;
				}
			if(flag) j=flag-1;
			else num[vec[j].first]++;
		}	
	} 
	for(int i=1;i<=m;i++)
		cout<<num[i]<<' ';
	return 0;
} 
