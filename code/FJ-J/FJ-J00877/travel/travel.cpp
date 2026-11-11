#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)printf("1");
	else{
		printf("0000");
		return 0;
	}
	a+=s1[0];
	a+=s1[1];
	b+=s2[0];
	b+=s2[1];
	if(a==b)printf("1");
	else{
		printf("000");
		return 0;
	}
	c=s1[2];
	d=s2[2];
	if((c=='D'||c=='F')&&(d=='D'||d=='F'))printf("1");
	else if(c!='D'&&c!='F'&&d!='D'&&d!='F')printf("1");
	else{
		printf("00");
		return 0;
	}
	if((c=='A'&&d=='C')||(c=='C'&&d=='A')){
		printf("0");
		return 0;
	}
	printf("1");
	return 0;
}
