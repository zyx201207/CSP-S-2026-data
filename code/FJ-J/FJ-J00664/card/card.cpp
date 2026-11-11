#include<iostream>
#include<stack>
using namespace std;
int a[200001],c[100001];
bool b[100001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		stack<int> s;
		for(int j=i;j<=n;j++)
		{
			if(!b[a[j]])
			{
				b[a[j]]=1;
				s.push(a[j]);
			}
			else
			{
				while(s.top()!=a[j])
				{
					b[s.top()]=0;
					s.pop();
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			c[j]+=b[j];
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",c[i]);
	return 0;
}
