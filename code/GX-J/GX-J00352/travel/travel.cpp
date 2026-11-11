#include<bits/stdc++.h>
using namespace std;
char ache[5],azuo[5],bche[5],bzuo[5];
void lin(){
	if(azuo[2]==bzuo[2]+1){
		printf("1");
		return;
	}
	if(azuo[2]==bzuo[2]-1){
		printf("1");
		return;
	}
	printf("0");
	return;
}
void ce(){
	if('A'<=azuo[2] and azuo[2]<='C'){
		if('A'<=bzuo[2] and bzuo[2]<='C'){
			printf("1");
			lin();
			return;
		}
	}
	if('D'<=azuo[2] and azuo[2]<='E'){
		if('D'<=bzuo[2] and bzuo[2]<='E'){
			printf("1");
			lin();
			return;
		}
	}
	printf("00");
	return;
}
void lie(){
	for(int i=0;i<2;i++){
		if(azuo[i]!=bzuo[i]){
			printf("000");
			return;
		}
	}
	printf("1");
	ce();
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",ache,azuo,bche,bzuo);
//	printf("%s%s%s%s",ache,azuo,bche,bzuo);
	for(int i=0;i<2;i++){
		if(ache[i]!=bche[i]){
			printf("0000");
			return 0;
		}
	}
	printf("1");
	lie();
	return 0;
}
