#include<bits/stdc++.h>
using namespace std;
bool check1(char x,char y)
{
	if(x>y)swap(x,y);
	if((x=='A'&&y=='B')||(x=='A'&&y=='C')||(x=='B'&&y=='C')||(x=='D'&&y=='F'))	
	return 1;     
	return 0;
}
bool check2(char x,char y)
{
	if(x>y)swap(x,y);
	if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F')
	return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	bool a=0,b=0,c=0,d=0;
	if(s1==s2)a=1;
	if(a&&c1.substr(0,2)==c2.substr(0,2))b=1;
	if(b&&check1(c1[2],c2[2]))c=1;
	if(c&&check2(c1[2],c2[2]))d=1;     
	printf("%d%d%d%d",a,b,c,d);
	return 0;
}