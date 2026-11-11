#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];           
map<int,int> mp,ans;
stack<int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<n;
	}
	else 
	{
		for(int k=1;k<=n;k++)
		{
			for(int i=k;i<=n;i++)
			{
				if(mp[a[i]])
				{
					while(st.top()!=a[i])
					{
						mp[st.top()]=0;
						st.pop();
					}
					st.pop();
				}
				st.push(a[i]);
				mp[a[i]]=1;
			}
			while(!st.empty())
			{
				ans[st.top()]++;
				mp[st.top()]=0;
				st.pop();
			}
		}
		for(auto i:ans)
		{
			//cout<<i.second()<<" ";
		}
	}
	return 0;
}
