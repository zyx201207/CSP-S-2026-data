#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x1,x2,x3,x4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1=(c1==c2);
	x2=(x1&&s1[0]==s2[0]&&s1[1]==s2[1]);
	int f1=s1[2],f2=s2[2];
	if(((f1<='C')==(f2<='C'))&&x2)
		x3=1;
	else x3=0;
	if((abs(f1-f2)==1)&&x3)
		x4=1;
	else x4=0;
	cout<<x1<<x2<<x3<<x4;
	return 0;
} 
