#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,s,d,f;
	cin>>a>>s>>d>>f;
if(a>1&&a<16&&d>1&&d<16)
{
	cout<<1;
}
else
{
	cout<<"0000";
	return 0;
}
if(a==d)
{
	cout<<1;
}
else
{
	cout<<"000";
	return 0;
}
if(s==f)
{
	cout<<1;
}
else
{
	cout<<"00";
	return 0;
}
	return 0;
}
