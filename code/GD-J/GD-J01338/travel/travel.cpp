#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5];
inline int side(char a){
	if(a=='A'||a=='B'||a=='C')return 1;
	else return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",a,b,c,d);
	if(a[0]==c[0]&&a[1]==c[1]){
		if(b[0]==d[0]&&b[1]==d[1]){
			if(side(b[2])==side(d[2])){
				if(abs(d[2]-b[2])==1){
					printf("1111");
				}else printf("1110");
			}else printf("1100");
		}else printf("1000");
	}else printf("0000");
	return 0;
}
