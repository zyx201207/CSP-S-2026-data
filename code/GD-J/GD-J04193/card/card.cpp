#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool y[300005]; 
int ans[1000005];
int zui[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		stack<int> st;
		for(int j=i;j<=n;j++)
		{
			st.push(a[j]);
			for(int h=n;h>=j+1;h--)
			{
				if(a[h]==a[j])
				{
					j=h; 
				} 
			}
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		 } 
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
 } 
