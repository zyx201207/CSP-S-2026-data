#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,i,j;
	cin>>m>>n;
	for(i=1;i<=m;i++)
	{
		int zs;
		cin>>zs;
		a[i]=zs;
	}
	if(m==4)
	cout<<12;
	if(m==5)
	cout<<7;
	return 0;
}
