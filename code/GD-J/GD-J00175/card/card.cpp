#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5,N=5e5+5;
bool Is[M];
int a[N],ans[M];
queue<int>q1,q2;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(n)
	{
		for(int i=1;i<=n;i++)
		{
			if(!Is[a[i]])
			{
				Is[a[i]]=1;
				q1.push(a[i]);
			}
			else
			{
				bool f=0;
				while(!q1.empty())
				{
					if(q1.front()==a[i]) f=1;
					if(!f)
						q2.push(q1.front());
					q1.pop();
				}
				while(!q2.empty())
				{	
					q1.push(q2.front());
					ans[q2.front()]++;
					q2.pop();
				}
				break;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
 }  
