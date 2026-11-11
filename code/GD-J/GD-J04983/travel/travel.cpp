#include <iostream>
using namespace std;
bool f(char c)
{
	return c=='A'||c=='B'||c=='C';
	}
int main()
{
	int a,x;
	char b[10],y[10];
	bool bo;
	cin>>a>>b>>x>>y;
	if(a!=x)
	{cout<<"0000";return 0;}
	cout<<1;
	if(!((b[0]==y[0])&&(b[1]==y[1]))){cout<<"000";return 0;}
	cout<<1;
	if(f(b[2])!=f(y[2])){cout<<"00";return 0;}
	cout<<1;
	if(b[2]=='F')b[2]--;
	if(y[2]=='F')y[2]--;
	cout<<(abs(b[2]-y[2])==1);
	return 0;
}
