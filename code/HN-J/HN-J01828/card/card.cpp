#include <bits/stdc++.h>
using namespace std;
int b,m,n,j,i,k=1,a[500001],desk[300001];
void pd()
{
	int q;
	for(q=1;q<=j;q++)
		if(desk[q]==desk[j])
		{
			for(int w=q;w<j;w++)
				desk[w]=-1*w;
		}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
	{
		b=0;
		for(k=1;k<=n;j++,k++)
		{
			desk[j]=a[k];
			pd();
		}
		for(j=1;j<=n;j++)
			if(desk[j]==i)
				b++;
			cout<<b<<" ";
	}
	return 0;
}
