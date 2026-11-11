#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	for(int i = 1;i<=2;i++)
		cin>>c1[i];
	for(int i= 1;i<=3;i++)
		cin>>s1[i];
	for(int i = 1;i<=2;i++)
		cin>>c2[i];
	for(int i= 1;i<=3;i++)
		cin>>s2[i];
	if(c1[2] != c2[2])
	{
		cout<<"0000";
		return 0;
	}
	for(int i = 1;i<=4;i++)
	{
		if(c1[2]==c2[2]&&i==1)
			a[i] = 1;
		if(s1[1]==s2[1]&&s1[2]==s2[2]&&i==2)
			a[i] = 1;
		if(s1[3]>='A'&&s1[3]<='C'&&s2[3]>='A'&&s2[3]<='C'&&i==3&&a[2]==1)
			a[i] = 1;
		if(s1[3]>='D'&&s1[3]<='F'&&s2[3]>='D'&&s2[3]<='F'&&i==3&&a[2]==1)
			a[i] = 1;
		int j = s1[3] - s2[3];
		if(j<0)
			j = j * -1;
		if(j==1&&s1[3]!='C'&&s1[3]!='D'&&i==4&&a[3]==1)
			a[i] = 1;
		if(j==1&&s1[3]!='D'&&s1[3]!='C'&&i==4&&a[3]==1)
			a[i] = 1;
	}
	for(int i = 1;i<=4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
