#include<iostream>
#include<conio.h>
using namespace std;
int a,b;
string a1,b1,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		c[0]='1';
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			c[1]='1';
			if((a1[2]!='C'&&b1[2]!='D')&&(a1[2]!='D'&&b1[2]!='C')){
				c[2]='1';
				if((a1[2]=='A'&&b1[2]=='B')||(a1[2]=='B'&&b1[2]=='A')||(a1[2]=='B'&&b1[2]=='C')||(a1[2]=='C'&&b1[2]=='B')||(a1[2]=='D'&&b1[2]=='E')||(a1[2]=='E'&&b1[2]=='D')){
					c[3]='1';
				}
				else c[3]='0';
			}
			else{
				c[2]='0';
				c[3]='0';
			}
		}
		else {
			c[1]='0';
			c[2]='0';
			c[3]='0';
		}	
	}
	else {
		c[0]='0';
		c[1]='0';
		c[2]='0';
		c[3]='0';
	}
	cout<<c[0]<<c[1]<<c[2]<<c[3];
	return 0;
}