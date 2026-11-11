#include <bits/stdc++.h>
using namespace std;
string c1[2],s1[3],c2[2],s2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0,c=0,d=0;
	cin >> c1[2]>>s1[3] >>c2[2] >>s2[3];
	if(c1[2]==c2[2]&&c1[2]!="01"&&c1[2]!="16")
	a=1;
	else a=0;
	if (size.s1(1)==size.s2(1)&&size.s1(2)==size.s2(2)&&a==1)
	b=1;
	else b=0;
	int z[6]=A,B,C,D,F;
	for (int n=0;n<3,n++){
		if(size.s1(3)==z[n]&&size.s2(3)==z[4]||size.s2(3)==z[3])
		c=0;
		break;
		if(size.s1(3)==z[3]||size.s1(3)==z[4]&&size.s2(3)==z[n])
		c=0;
		break;
		else c=1;
		break;
	}
	for(int n=0;n<=3&&n!=2;n++){	
		if(size.s1(3)+size.s2(3)==z[n]+z[n+1]&&c!=0)
		d=1; 
		break;
		else d=0;
	}
	cout << a<<b<<c<<d<<endl;
	return 0;
}
