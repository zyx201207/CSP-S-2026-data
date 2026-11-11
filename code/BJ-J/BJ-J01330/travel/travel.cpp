#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    int p1=int(s1[0])-int('0');
    p1*=10;
    p1+=int(s1[1])-int('0');
    int p2=int(s2[0])-int('0');
    p2*=10;
    p2+=int(s2[1])-int('0');
    if(c1==c2&&p1==p2)
    {
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	bool zuo1=s1[2]>='A'&&s1[2]<='C';
	bool zuo2=s2[2]>='A'&&s2[2]<='C';
	if(((zuo1&&zuo2)||(!zuo1&&!zuo2))&&c1==c2&&p1==p2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(((abs(int(s1[2])-int(s2[2])))==1)&&((zuo1&&zuo2)||(!zuo1&&!zuo2))&&c1==c2&&p1==p2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
    return 0;
}
