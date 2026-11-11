#include<bits/stdc++.h>
using namespace std;
long long n,m,num[300005],ans[300005],c[500005],i,i1=1;
stack<int> card;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int k=1;k<=n;k++)cin>>c[k]; 
	
	for(i1;i1<=n;)
	{
		
		while(!card.empty()) card.pop();
		for(int k=1;k<=m;k++)
		{
			num[k]=0;
		}
		
		i=i1;
		for(i;i<=n;i++)
		{
			if(num[c[i]]!=0)
			{
				while(card.top()!=c[i])
				{
					num[card.top()]--;
					card.pop();
				}
				num[card.top()]--;
				card.pop();
				
			}
			card.push(c[i]);
			num[c[i]]++;
		}
		
		for(int k=1;k<=m;k++)
		{
			if(num[k]!=0)
			{
				ans[k]++;
			}
		}
		i1++;
	}
	
	for(int k=1;k<=m;k++)
	{
		cout<<ans[k]<<" ";
	}
	return 0;
}
