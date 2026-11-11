#include<bits/stdc++.h>
using namespace std;
int num[300001],a[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int b[300001]={0};
		int t=1;
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
			if(b[a[j]]==2)
			{
				t=t+j-1;
				b[a[j]]--;
			}
		}
		for(int j=t;j<=n;j++)
		{
			num[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
