#include<bits/stdc++.h>
using namespace std;
int n,m,l[200005],t[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int a=1;a<=n;a++)
	{
		cin>>l[a];
	}
	for(int a=1;a<=n;a++)
	{
		int k[200005]={0},q[200005]={0};
		for(int b=a;b<=n;b++)
		{	
			if(k[l[b]]!=0)
			{
				for(int c=k[l[b]];c<b;c++)
				{
					k[q[c]]=0;
					q[c]=0;
				}	
			}
			k[l[b]]=b,q[b]=l[b];
		}
		for(int b=1;b<=m;b++)
			t[b]+=(k[b]!=0);
	}
	for(int a=1;a<=m;a++) cout<<t[a]<<' ';
	return 0;
}