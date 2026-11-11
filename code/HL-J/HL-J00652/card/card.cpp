#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
stack<int>stk;
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


	for(int i=1;i<=n;i++){

			stk.push(a[i]);
			b[i]=a[i];
			for(int j=1;j<=m;j++)
			{
				if(b[j]==a[i])
				{
					while(stk.top()!=a[i])
					{
						stk.pop();
					}
					stk.push(a[i]);
				}
				else
				{
					stk.push(a[i]);
				 }
			}
		}
			c[stk.top()]++;
			stk.pop();
			for(int k=1;k<=m;k++)
			{
				cout<<c[k]<<' ';
			}
		return 0;


}
