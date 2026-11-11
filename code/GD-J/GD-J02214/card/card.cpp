#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int n,m,a[500005],vis[500005],ans[500005],bns[500005];
stack<int>s;
bool b=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])b=0;
	}
	if(b)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])
			{
				bns[a[i]]++;
			}
			else
			{
				bns[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<bns[i]<<' ';
		}
		return 0;
	}
	int k=1;
	while(k<=n)
	{
		//cout<<k<<endl;
		for(int i=k;i<=n;i++)
		{
			//cout<<i<<"! ";
			if(vis[a[i]])
			{
				while(s.top()!=a[i])
				{
					int x=s.top();
					s.pop();
					vis[x]--;
					//cout<<x<<'^'<<endl;
				}
			}
			else
			{
				s.push(a[i]);
				vis[a[i]]++;
			}
		}
		while(!s.empty())
		{
			int x=s.top();
			ans[x]++;
			s.pop();
		}
		k++;
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}//4 3 1 2 1 3
