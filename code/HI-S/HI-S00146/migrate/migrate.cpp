#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int jfk,q;
	int h,k;
	cin>>jfk>>q;
	while(q--)
	{
		cin>>h>>k;
		for(int i=1;i<=h;i++)
		{
			cin>>a[i];
		}
		int y=a[2]-a[1];
		y=k/y;
		y=y*2;
		cout<<h-y+1;
	}
	return 0;
}
