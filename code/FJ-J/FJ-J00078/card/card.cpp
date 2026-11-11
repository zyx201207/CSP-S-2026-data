#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=2e5+5;
int n,m,a[MAX];
vector<int> card_in_desktop; 
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int cnt=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=0;k<card_in_desktop.size();k++)
			{
				if(a[j]==card_in_desktop[k])
				{
					for(int i=0;i<n-k;i++)
					{
						card_in_desktop.pop_back();
					}
				}
			}
			card_in_desktop.push_back(a[j]);
		}
		for(int j=0;j<card_in_desktop.size();j++)
		{
			if(card_in_desktop[j]==i)cnt++;
		}
		cout<<cnt<<" ";
		card_in_desktop.clear();
	}
	system("")
	return 0;
}
