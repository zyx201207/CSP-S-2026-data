#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,m,a[N],t[N];
stack<int> st;
bool b[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(!b[a[j]]) 
			{
				st.push(a[j]);
				b[a[j]]=true;
			}
			else 
			{
				while(st.top()!=a[j])
				{
					b[st.top()]=false;
					st.pop();
				}
			}
		}
		for(int j=1;j<=m;j++)
			if(b[j]) t[j]++;
		memset(b,0,sizeof b);
	}
	for(int i=1;i<=m;i++)
		cout<<t[i]<<' ';
	return 0;
}
