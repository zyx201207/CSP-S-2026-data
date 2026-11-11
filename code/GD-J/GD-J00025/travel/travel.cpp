#include<bits/stdc++.h>
using namespace std;
inline int R(char x){return x-'0';}
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1!=c2){
		printf("0000");
		return 0;
	}
	int num1,num2;
	num1=R(s1[0])*10+R(s1[1]);
	num2=R(s2[0])*10+R(s2[1]);
	if (num1!=num2){
		printf("1000");
		return 0;
	}
	int se1,se2;
	se1=s1[2]-'A';
	se2=s2[2]-'A';
	bool p1=se1<'D'-'A',p2=se2<'D'-'A';
	if (p1!=p2){
		printf("1100");
		return 0;
	}
	if (se1-se2==1||se1-se2==-1){
		printf("1111");
	}
	else{
		printf("1110");
	}
	return 0;
}
