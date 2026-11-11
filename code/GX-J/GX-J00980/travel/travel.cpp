#include<iostream>
#include<cstdio>
using namespace std;
int a1,b1,a2,b2;
char c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if(a1!=a2)  {cout<<"0000"; return 0;}
	cout<<'1';
	if(b1!=b2)  {cout<<"000"; return 0;}
	cout<<'1';
	if(('A'<=c1 && 'C'>=c1 && 'A'<=c2 && 'C'>=c2) || ('D'<=c1&&'F'>=c1&&'D'<=c2&&'F'>=c2))
	  cout<<'1';
	else  {cout<<"00"; return 0;}
	if(c1+1==c2||c2+1==c1)
	  cout<<'1';
	else
	  cout<<'0';
	return 0;
}
