#include <bits/stdc++.h>
using namespace std;

int a[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	a[0]=1;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		a[1]=1;
		if(s1[2]<'D'&&s2[2]<'D')
		a[2]=1;
		if(s1[2]>='D'&&s2[2]>='D')
		a[2]=1;
	}
	if(a[2]==1&&s1[2]-'0'+1==s2[2]-'0')
	{
		a[3]=1;
	}
	if(a[2]==1&&s1[2]-'0'-1==s2[2]-'0')
	{
		a[3]=1;
	}
	for(int i=0;i<=3;i++)
	{
		cout<<a[i];
	}
	return 0;
}
