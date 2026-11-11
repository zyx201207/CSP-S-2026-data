#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool check(int l,int r,int c)
{
	bool x=0;
	for(int i=l;i<=r;i++)
	{
		if(a[i]==c)
		{
			x=1;
			break;
		}
	}
	if(x==1)return 1;
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int t=0;
		for(int j=1;j<=n;j++)
		{
			if(check(j,n,i))t++;
		}
		cout<<t<<" ";
	}
	return 0;
}
