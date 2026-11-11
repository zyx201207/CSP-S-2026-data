#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1,r2,h1,h2;
	string c1,s1,c2,s2;
	cin>>s1>>c1>>s2>>c2;
	r1=(c1[0]-'0')*10+(c1[1]-'0'),r2=(c2[0]-'0')*10+(c2[1]-'0');
	h1=c1[2]-'A',h2=c2[2]-'A';
	if(s1==s2){
		printf("1");
		if(r1==r2){
			printf("1");
			if((h1<=2&&h2<=2)||(h1>2&&h2>2)){
				printf("1");
				if(h1==5) h1=4;
				if(h2==5) h2=4;
				if(abs(h1-h2)<=1&&(!((h1==2&&h2==3)||(h1==3&&h2==2))))
					printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000"); 
	return 0;
} 
