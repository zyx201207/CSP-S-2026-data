#include<bits/stdc++.h>
using namespace std;
string sum;
int c1,c2,s1,s2,z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&c1,&s1,&z1,&c2,&s2,&z2);
	if(c1==c2){}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2){}
	else{
		cout<<"1000";
		return 0;
	}
	if('D'<=z1&&'F'>=z1&&'D'<=z2&&'F'>=z2||
	'A'<=z1&&'C'>=z1&&'A'<=z2&&'C'>=z2){}
	else{
		cout<<"1100";
		return 0;
	}
	if(z1=='A'&&z2=='B'||z1=='B'&&z2=='A'||
	z1=='B'&&z2=='C'||z1=='C'&&z2=='B'||
	z1=='D'&&z2=='F'||z1=='F'&&z2=='D'){}
	else{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
