#include<bits/stdc++.h>
using namespace std;
int n,m,js[300005],a[500005];
bool check(int w,stack<int>q)
{
	while(!q.empty())
	{
		if(q.top()!=w) q.pop();
		else return true;
	}
	return false;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		stack<int>q;
		for(int j=i;j<=n;j++)
		{
			if(!check(a[j],q)) q.push(a[j]);
			else 
			{
				while(q.top()!=a[j]) q.pop();
			}
		}
		while(!q.empty())
		{
			int x=q.top();
			js[x]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<js[i]<<" ";
	cout<<"\n";
	return 0;	
} 
