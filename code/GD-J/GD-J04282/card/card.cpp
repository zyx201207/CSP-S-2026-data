#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
long long a[500005],b[300005];
int vis[500005];
stack<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==1)
			{
//				cout<<"yy: "<<a[j]<<endl;
//				cout<<"XXX"<<endl;
				while(q.top()!=a[j])
				{
					vis[q.top()]=0;
//					cout<<"xx: "<<q.top()<<endl;
					q.pop();
				}
			}
			else
			{
//				cout<<"YYY"<<endl;
				vis[a[j]]=1;
				q.push(a[j]);
			}
		}
		while(q.empty()==false)
		{
//			cout<<q.top()<<" ";
			b[q.top()]++;
			q.pop();
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
