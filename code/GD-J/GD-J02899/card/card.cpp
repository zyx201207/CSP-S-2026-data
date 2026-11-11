#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[300005]={0},v[500005]={0},i=0,q[500005]={0},w=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int op=n;
	for(int j=1;j<=n;j++)
	{
		cin>>q[j];
	 } 
	while(op--)
	{
		i=0;
		for(int t=w;t<=n;t++){
			int x=q[t];
			bool ok=1;
			int p=0;
			for(int j=1;j<=i;j++)
			{
				if(v[j]==x) {
					ok=0;
					p=j;
				}
			}
			if(ok)
			{
				i++;
			}
			else
			{
				i=p;
			}
			v[i]=x;
		}
		for(int j=1;j<=i;j++)
		{
			a[v[j]]++;
		}
		w++;
	}
	for(int j=1;j<=m;j++) cout<<a[j]<<" ";
	return 0;
} 
