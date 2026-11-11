#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,r1[6],r2[6];
	int a[m];
	for(int i=1;i<=m;i++)
	{
		cin>>a[m];
	}
	int p=1,q=1;
	for(int i=1;i<=m;i++)
	{
		if(a[i]==1)
		{
			r1[p]=i;
			p++;
		}
		if(a[i]==2)
		{
			r2[q]=i;
			q++;
		}
	}
	if(m==n)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<m;
		}
	}
	else{
		for(int i=1;i<=m;i++)
		{
			cout<<1;
		}
	}
	return 0;
}
