#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],card[300005],ans[300005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long st=0;
	while(st<n)
	{
		memset(card,0,sizeof(card));
		for(int i=st;i<n;i++)
		{
			if(card[a[i]])
			{
				for(int j=i-1;j>=0;j--)
				{
					card[a[j]]=0;
					if(a[j]==a[i])
						break;
				}
				card[a[i]]++;
			}
			else
			{
				card[a[i]]++;
			}
		}
		for(int i=1;i<=m;i++)
			if(card[i])
				ans[i]++;
		st++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
