#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
struct dd
{
	int fx;
	char x,y,z;
};
int ans=0,flag=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	dd a[2];
	string ans[3];
	for(int i=1;i<=2;i++)
		cin>>a[i].fx>>a[i].x>>a[i].y>>a[i].z;
	if(a[1].fx==a[2].fx)
		ans[3]=1;
	if(a[1].x==a[2].x && a[1].y==a[2].y)
		ans[2]=1;
	if(a[1].x==a[2].x && a[1].y==a[2].y)
	{
		if(a[1].z=='A' && (a[2].z=='B' || a[2].z=='C'))
			ans[1]=1;
		if(a[1].z=='B' && (a[2].z=='A' || a[2].z=='C'))
			ans[1]=1;
		if(a[1].z=='C' && (a[2].z=='A' || a[2].z=='B'))
			ans[1]=1;		
		if(a[1].z=='D' && a[2].z=='E')
			ans[1]=1;
		if(a[1].z=='E' && a[2].z=='D')
			ans[1]=1;
	}
	if(a[1].x==a[2].x && a[1].y==a[2].y)
	{
		if(a[1].z=='A' && a[2].z=='B')
			ans[0]=1;
		if(a[1].z=='B' && (a[2].z=='A' || a[2].z=='C'))
			ans[0]=1;
		if(a[1].z=='C' && a[2].z=='B')
			ans[0]=1;		
		if(a[1].z=='D' && a[2].z=='E')
			ans[0]=1;
		if(a[1].z=='E' && a[2].z=='D')
			ans[0]=1;
	}
	
	cout<<ans;
	return 0;
}
