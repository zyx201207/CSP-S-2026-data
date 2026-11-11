#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,p1,p2;
int h1,h2;
map<char,int> book;
void check()
{
	p1=s1[0]+s1[1];
	p2=s2[0]+s2[1];
	h1=book[s1[2]];
	h2=book[s2[2]];
	if(c1!=c2) 
	{
		printf("0000");
		return;	
	}
	printf("1");
	if(p1!=p2) 
	{
		printf("000");
		return;
	}
	printf("1");
	if((h1<=3 and h2>=4) or (h1>=4 and h2<=3)) 
	{
		printf("00");
		return;
	}
	printf("1");
	if(h1>=4 && h2>=4) 
	{
		printf("1");
		return;
	}
	if(abs(h2-h1)==1)
	{
		printf("1");
		return;
	}
	printf("0");
	return;
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	book['A']=1;
	book['B']=2;
	book['C']=3;
	book['D']=4;
	book['F']=5;
	cin>>c1>>s1>>c2>>s2;
	check(); 
	return 0;
}
