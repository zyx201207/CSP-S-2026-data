#include<bits/stdc++.h>
using namespace std;
bool flag[300005];
int ans[300005];
stack <int> s;
int m;
int n;
int card[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			flag[card[j]]=false;
		}
		for(int j=i;j<=n;j++)
		{
			if(flag[card[j]]==false)
			{
				s.push(card[j]);
				flag[card[j]]=true;
			 }
			 else if(flag[card[j]]==true)
			 {
			 	while(s.top()!=card[j])
			 	{
					flag[s.top()]=false;
		 			s.pop();
				 }
			 }
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			s.pop();
		}	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
