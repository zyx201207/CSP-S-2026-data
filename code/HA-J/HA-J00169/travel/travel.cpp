#include <bits/stdc++.h>
using namespace std;

char a[5],b[5];
char c1[10],c2[10];
bool t = 1;

int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",a+1,c1+1,b+1,c2+1);
	if(a[1] == b[1] &&a[2] == b[2]){
		printf("1");
	}
	else{
		t = 0;
		printf("0");
	}
	if((c1[1] == c2[1] && c1[2] == c2[2]) && t){
		printf("1");
	}
	else{
		t = 0;
		printf("0");
	}
	if(((c1[3] == 'C' && c2[3] == 'D')||(c1[3] == 'D' && c2[3] == 'C')) || !t){
		t = 0;
		printf("0");
	}
	else{
		printf("1");
	}
	if((c1[3] - c2[3] == 1||c2[3]-c1[3] == 1)&&t){
		printf("1");
	}
	else{
		printf("0");
	}
	return 0;
}
