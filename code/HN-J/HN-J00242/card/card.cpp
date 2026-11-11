#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
vector<int> card;
signed main()
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
		int cnt=0;
		for(int j=i;j<=n;i++)
		{
			card.push_back(a[i]);
			for(int k=i;k<=j;k++)
			{
				if(a[k]==a[j]&&j!=k)
				{
					for(int l=k;l<=j;l++)
					{
						card[l]=-1;
					}
				}
			}
		}
		for(int j=1;j<=card.size();j++)
		{
			if(a[j]==i)cnt++;
		}
		cout<<cnt<<" ";
	}
	return 0;
}

