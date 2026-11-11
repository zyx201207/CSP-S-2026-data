#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b)
{
	if(a=='A'&&b=='B')return true;
	if(a=='B'&&b=='A')return true;
	if(a=='A'&&b=='C')return true;
	if(a=='C'&&b=='A')return true;
	if(a=='D'&&b=='E')return true;
	if(a=='E'&&b=='D')return true;
	if(a=='C'&&b=='B')return true;
	if(a=='B'&&b=='C')return true;
	return false;
}
bool check2(char a,char b)
{
	if(a=='A'&&b=='B')return true;
	if(a=='B'&&b=='A')return true;
	if(a=='C'&&b=='D')return true;
	if(a=='D'&&b=='C')return true;
	if(a=='D'&&b=='E')return true;
	if(a=='E'&&b=='D')return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	bool flag=0,flag1=0,flag2=0,flag3=0;
	if(c1==c3)flag=1;
	if(c1==c3&&c2.substr(0,2)==c4.substr(0,2))flag1=1;
	if(c1==c3&&c2.substr(0,2)==c4.substr(0,2)&&check(c2[2],c4[2]))flag2=1;
	if(c1==c3&&c2.substr(0,2)==c4.substr(0,2)&&check(c2[2],c4[2])&&check2(c2[2],c4[2]))flag3=1;
	cout<<flag<<flag1<<flag2<<flag3<<endl;
	return 0;
}