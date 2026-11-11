#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
long long k[300005];
stack<int> st;


signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		while(!st.empty()) st.pop();
		bool p[300005]={0};
		int now=0;
		for(int j=i;j<=n;j++)
		{
			if(p[a[j]]==0)
			{
				p[a[j]]=1;
				st.push(a[j]);
			}
			else
			{
				while(!st.empty()&&st.top()!=a[j])
				{
					p[st.top()]=0;
					st.pop();
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(p[j]) k[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << k[i] <<' ';
	}
	return 0;
}
