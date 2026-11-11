#include <bits/stdc++.h>
using namespace std;
bool check(char x,char y)
{
	if(x=='A' && y=='B') return 1;
	if(x=='B' && y=='C') return 1;
	if(x=='B' && y=='A') return 1;
	if(x=='C' && y=='B') return 1;
	if(x=='D' && y=='F') return 1;
	if(x=='F' && y=='D') return 1;
	return 0;
}
bool checkp(char x,char y)
{
	if('A'<=x && x<='C' && 'A'<=y && y<='C') return 1;
	if((x=='D' || x=='F') && (y=='D' || y=='F')) return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,p1,p2;
	string s1,s2;
	bool d1,d2,d3,d4;
	char l1,l2;
	cin>>c1>>s1>>c2>>s2;
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	l1=s1[2],l2=s2[2];
	d1=(c1==c2);
	d2=d1&&(p1==p2);
	d3=d2&&checkp(l1,l2);
	d4=d2&&check(l1,l2);
	cout << d1 << d2 << d3 << d4;
	return 0;
}
