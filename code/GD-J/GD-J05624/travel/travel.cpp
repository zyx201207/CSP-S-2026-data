#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	cin>>a;
	string b,d;
	cin>>b;
	cin>>c;
	cin>>d;
	cout<<(a==c);
	cout<<(a==c)&&(b[0]==d[0]&&b[1]==d[1]);
	bool b1=(b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C');
	bool b2=(b[2]=='F'||b[2]=='E')&&(d[2]=='F'||d[2]=='E');
	cout<<(a==c)&&(b[0]==d[0]&&b[1]==d[1]&&(b1||b2));
	int num1=b[2]-d[2];
	int num2=d[2]-b[2];
	bool isnear=(num1==1||num2==1)&&(b[2]!='C'&&d[2]!='E')&&(d[2]!='C'&&b[2]!='E');
	cout<<(a==c)&&(b[0]==d[0]&&b[1]==d[1]&&isnear);
	return 0;
}
