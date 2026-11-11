#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int a[500010],h[300010],ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m>2000)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<m-i+1<<" ";
		}
	}
	while(++cnt<=n)
	{
		memset(h,0,sizeof(h));
		for(int i=cnt;i<=n;i++)
		{
			if(h[a[i]]==0)
			{
				st.push(a[i]);
				h[a[i]]++;
			}
			else
			{
				while(st.size())
				{
					if(st.top()!=a[i])
					{
						h[st.top()]--;
						st.pop();
					}
					else break;
				}
			}
		}
		while(st.size())
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
