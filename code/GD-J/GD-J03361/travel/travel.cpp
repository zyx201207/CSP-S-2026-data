#include<bits/stdc++.h>
using namespace std;
char a1[5],a2[5],b1[5],b2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",a1+1,a2+1,b1+1,b2+1);
	if(a1[1]==b1[1]&&a1[2]==b1[2]){
		if(a2[1]==b2[1]&&a2[2]==b2[2]){
			if((a2[3]<='C')==(b2[3]<='C')){
				if( (a2[3]=='A'&&b2[3]=='B')||
					(a2[3]=='B'&&b2[3]=='A')||
					(a2[3]=='B'&&b2[3]=='C')||
					(a2[3]=='C'&&b2[3]=='B')||
					(a2[3]=='D'&&b2[3]=='F')||
					(a2[3]=='F'&&b2[3]=='D')){
					puts("1111");
				}else puts("1110");
			}else puts("1100");
		}else puts("1000");
	}else puts("0000");
	return 0;
}
