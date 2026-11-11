#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,p;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]+=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=0)
		cout<<i<<" ";
	}
	return 0;
}
