//GZ-J00282,贵阳市花溪第一中学，刘令皓；
#include<iostream>
using namespace std;
int main()
{
    freopen(travel,in,r,stdin);
    freopen(travel,out,w,stdout);
	int a[4],b,c[3],d,e[3];
    cin>>b>>d>>c[3]>>e[3];
    if(b==d)
    {
    	a[0]=1;
	}
	else
	{
		a[0]=0;
	}
	if(c[0]==e[0])
	{
		a[1]=1;
	}
	else
	{
		a[1]=0;
	}
	if(c[1]==e[1])
	{
		a[2]=1;
	}
	else
	{
		a[2]=0;
	}
	if(c[2]==e[2]+1||c[2]==e[2]-1)
	{
		a[3]=1;
	}
	else
	{
		a[3]=0;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}


