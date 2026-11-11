#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int abs(int x){
	if(x>0) return x;
	return -x;
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		printf("1");
		int a1=s1[0]*10+s1[1],a2=s2[0]*10+s2[1];
		if(a1==a2){
			printf("1");
			char ch1=s1[2],ch2=s2[2];
			//printf("%c%c",ch1,ch2);
			//if(ch1>'C'&&ch2>'C') printf("asdfghjkl");
			//if(ch1<='C'&&ch2<='C') printf("bbbb");
			if((ch1>'C'&&ch2>'C')||(ch1<='C'&&ch2<='C')){
				printf("1");
				if(abs(ch1-ch2)==1) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
