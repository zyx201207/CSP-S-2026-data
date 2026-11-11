#include<bits/stdc++.h>
using namespace std;
int n,m,a[555555],f[333333],as[333333];
stack<int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		memset(f,0,sizeof(f));
		for(int i=k;i<=n;i++)
		{
			if(!f[a[i]]) 
			{
				f[a[i]]=1;
				st.push(a[i]);
			}
			else
			{
				while(st.top()!=a[i])
				{
					f[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty())
		{
			as[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<as[i]<<' ';
	return 0;
}
