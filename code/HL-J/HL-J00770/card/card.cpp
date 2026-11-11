#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int z=5e5+9;
int n,m,ans[z];
int a[z];
bool book[z];
stack<int>s;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(book[a[j]]==0) 
			{
				book[a[j]]=1;
				s.push(a[j]);
			}
			else if(book[a[j]]==1)
			{
				while(s.top()!=a[j])
				{
					int t1=s.top();
					book[t1]=0;
					s.pop();
				} 
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(book[j]==1) ans[j]++;
		} 
		for(int j=1;j<=m;j++) book[j]=0;
		while(!s.empty()) s.pop();
	} 
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*

*/

