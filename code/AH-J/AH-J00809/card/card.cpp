# include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],card[N];
int n,m;
map<int,int> mp;
bool pd=1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) pd=0;
	}
	if(pd)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i+1]) continue;
			else mp[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
			cout<<mp[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int pos=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=pos;k++)
			{
				if(card[k]==a[j])
				{
					pos=k-1;
					break;
				}
			}
			pos++;
			card[pos]=a[j];
		}
		for(int j=1;j<=pos;j++)
			mp[card[j]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mp[i]<<" ";
	}
	return 0;
}
