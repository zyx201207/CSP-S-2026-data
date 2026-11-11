#include<bits/stdc++.h>
using namespace std;
int ca,cb;
char a[5],b[5];
bool fro;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&ca);
	scanf(" %s",a);
	scanf(" %d",&cb);
	scanf(" %s",b);
	if(ca==cb)printf("1");
	else{
		printf("0000");
		return 0;
	}
	if(a[0]==b[0]){
		if(a[1]==b[1]){
			printf("1");
		}
		else{
			printf("000");
			return 0;
		}
	}
	if(a[2]=='A'||a[2]=='B'||a[2]=='C'){
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			printf("1");
			fro=1;
		}
	}
	if(a[2]=='F'||a[2]=='D'){
		if(b[2]=='F'||b[2]=='D'){
			printf("1");
			fro=1;
		}
	}
	if(!fro){
		printf("00");
		return 0;
	}
	if(a[2]+1==b[2]||a[3]-1==b[2])printf("1");
	else
		printf("0");
	return 0;
}
