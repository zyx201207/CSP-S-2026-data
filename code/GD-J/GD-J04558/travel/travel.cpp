#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int d1=s1[2]-'A';
	int d2=s2[2]-'A';
	bool i1=(d1<=2&&d2<=2)||(d1>2&&d2>2),i2=(c1==c2),i3=(s1[0]==s2[0] && s1[1]==s2[1]);
	cout<<(i2);
	cout<<(i2&&i3);
	cout<<(i1&&i2&&i3);
	cout<<(i3&&i2&&i1&&(abs(d1-d2)==1)); 
}

