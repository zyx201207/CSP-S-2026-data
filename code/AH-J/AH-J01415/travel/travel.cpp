#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
	cout<<"0";
}
else cout<<"1";
for(i=0;i<=1;i++)
if(s1[i]-'0'!=s2[i]-'0')
	{
	cout<<"0";
}
else {
	if(i!=0)
	cout<<"1";
}
if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
cout<<"1";
else if(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E')
cout<<"1";
else {
	cout<<"00";
	return 0;
}
if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
cout<<"1";
else cout<<"0";
return 0;
}
