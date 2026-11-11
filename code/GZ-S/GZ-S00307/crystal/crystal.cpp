//GS-S00307 遵义航天高级中学 胡雯雯

#include <bits/stdc++.h>
using namespace std;

const int MAX=500005;
long long int n,m;
int a[MAX]={0};
int cont=1;

int xulie(int x,int y)
{
	if(a[x+1]==0)
	{
		cout<<cont;
	}
	else
	{
		if(a[x]!=a[x+1])
		{
			y=y+(a[x+1]-a[x])*cont;
			cont++;
		}
		else
		{
			cont++;
		}
		if(y<=m)
			return xulie(x+1,y);
		else
			cout<<cont-1;
	}
}

int main()
{

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	xulie(1,0);
	return 0;
}

