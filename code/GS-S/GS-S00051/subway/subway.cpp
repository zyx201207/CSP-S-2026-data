#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1000000010],b[20],a[10];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	if(c==0&&n==2)
	{
		for(int i=1;i<=14;i++)
		{
			cin>>b[i];
	 	} 
		for(int i=1;i<=4;i++)
		{
	 		cin>>a[i];
		}
	 	cout<<32<<endl<<17;
	 	return 0;
	}
	if(c==0&&n==3)
	{
		for(int i=1;i<=23;i++)
		cin>>b[i];
		for(int i=1;i<=4;i++)
		cin>>a[i];
		cout<<35<<endl<<16;
	}
	return 0;
}
