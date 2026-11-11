#include<bits/stdc++.h>
using namespace std;
struct iny
{
	int x ,y;
	char z;
}a[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	if(a[0].x!=a[1].x)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(a[0].y!=a[1].y)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	bool bo=true;;
	if((a[0].z=='A'||a[0].z=='B'||a[0].z=='C')
	&&(a[1].z=='A'||a[1].z=='B'||a[1].z=='C'))
	{
		bo=false;
	}
	else if((a[0].z=='D'||a[0].z=='F')
	&&(a[1].z=='D'||a[1].z=='F'))
	{
		bo=false;
	}
	if(bo)
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(a[0].z+1==a[1].z||a[0].z-1==a[1].z)
	{
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
