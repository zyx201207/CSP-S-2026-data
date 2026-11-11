#include<iostream>
#include<stack>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>i;
	}
	int x,k;
	for(int j=x;j<=n;j++)
	{
		if(j=j-1)
		{
			x++;
		}
		if(j!=k)
		{
			s.push(k);
		}
		else
		{
			s.pop();
		}
		cout<<j<<" ";
	}
}
