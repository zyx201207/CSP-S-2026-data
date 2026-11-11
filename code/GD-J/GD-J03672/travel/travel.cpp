#include <iostream>
using namespace std;
string x1,y1,x2,y2;
int main()
{
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout); 
	cin>>x1>>y1>>x2>>y2;
	if (x1!=x2)
		cout<<"0000";
	else if (y1[1]!=y2[1]||y1[0]!=y2[0])
		cout<<"1000";
	else if (y1[2]<='C'&&y2[2]>'C'||y1[2]>'C'&&y2[2]<='C')
		cout<<"1100";
	else if (y1[2]=='C'&&y2[2]=='A'&&y1[2]=='C'&&y2[2]=='A')
		cout<<"1110";
	else
		cout<<"1111";
	return 0;
} 
