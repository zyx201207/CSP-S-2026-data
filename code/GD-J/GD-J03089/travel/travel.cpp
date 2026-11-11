#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool A=1,B=1,C=1,D=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)A=1;
	else A=0;
	if(A&&s1[0]==s2[0]&&s2[1]==s1[1])B=1;
	else B=0;
	if(B&&((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))
		||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')))
		C=1;
	else C=0;
	if(C)
	{
		if((s1[2]=='D'&&s1[2]=='F')||(s1[2]=='F'||s1[2]=='D'))
			D=1;
		else if(s1[2]=='A'&&s2[2]=='B')D=1;
		else if(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A'))D=1;
		else if(s1[2]=='C'&&s2[2]=='B')D=1;
		else D=0;
	}
	else D=0;
	cout<<A<<B<<C<<D;
	return 0;
}
