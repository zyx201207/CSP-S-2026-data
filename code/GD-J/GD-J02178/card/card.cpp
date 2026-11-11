#include<bits/stdc++.h> 
using namespace std;
int m,n,ans[200001]={0};
queue<int>a;
bool b[300001]={0},b1[300001]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int d;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>d;
		a.push(d);
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<=m;j++)
		{
			if(!b[a.front()])
			{
				b[a.front()]=1;
				a.push(a.front());
				a.pop();
			}
		}
		for(int j=i;j<=m;j++)
		{
			if(!b1[a.front()])
			{
			ans[a.front()]++;
			b1[a.front()]=1;	
			}
			a.push(a.front());
			a.pop();
		}
		a.pop();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
