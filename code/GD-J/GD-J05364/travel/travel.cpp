#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char c[3],d[3];
	scanf("%d",&a);
	scanf("%c",&c[0]);
	for(int i=0;i<3;i++){
		scanf("%c",&c[i]);
	}
	scanf("%c",&d[0]);
	scanf("%d",&b);
	scanf("%c",&d[0]);
	for(int i=0;i<3;i++){
		scanf("%c",&d[i]);
	}
	if(a==b) printf("1");
	else {
		printf("0000");
		return 0;
	}
	if(c[0]==d[0]&&c[1]==d[1]) printf("1");
	else{
		printf("000");
		return 0;
	} 
	if(c[2]=='D'||c[2]=='F'){
		if(d[2]=='D'||d[2]=='F'){
			printf("11");
			return 0;
		}else{
			printf("00");
			return 0;
		}
	}else{
		if(d[2]!='D'&&d[2]!='F') printf("1");
		else{
			printf("00");
			return 0; 
		}
		if(d[2]=='B'||c[2]=='B'){
			printf("1");
		}else{
			printf("0");
		}
	}
	return 0;
}
