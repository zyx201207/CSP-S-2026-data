#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005];
stack<int>st;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
		int b;
		cin>>b;
		for(int j=i+1;j<=st.size();j++)
		{
			if(st[j]==b)
			{
				st.pop();
			}
		}
		for(int j=0;j<=st.size())
		{
			a[st[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i]<<" ";
	}
	//fclose(stdin);
	//fclose(stdout);
}
