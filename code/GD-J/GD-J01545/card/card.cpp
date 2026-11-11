#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	int i;
	int card[n];
	int stack[n];
	int jvshu[n];
	for(i=0;i<n;i++)
	{
		cin>>card[i];
		jvshu[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(card[j]==i)
			{
				jvshu[i]++;
			}
		}
	}
	cout<<jvshu;
}
