// SPDX-License-Identifier: MPL-2.0
#include<stdio.h>
#include<string.h>
int in_same_side(char a,char b){
    if(a=='A'||a=='B'||a=='C')return (b=='A'||b=='B'||b=='C');
    return (b=='D'||b=='E');
}
int side_by_side(char a,char b){
    if(a>b){
        char c=b;
        b=a;
        a=c;
    }
    if(a=='A')return b=='B';
    if(a=='B')return b=='C';
    if(a=='D')return b=='E';
    return 0;
}
int main(){
	FILE* in=fopen("travel.in","r");
	FILE* out=fopen("travel.out","r");
	char train_no_1[3],train_no_2[3],seat_no_1[4],seat_no_2[4],res[5]={};
	fscanf(in,"%s %s %s %s",train_no_1,seat_no_1,train_no_2,seat_no_2);
    res[0]=!memcmp(train_no_1,train_no_2,2);
    res[1]=!memcmp(seat_no_1,seat_no_2,2);
    res[1]&=res[0];
    res[0]+=48;
    res[2]=in_same_side(seat_no_1[2],seat_no_2[2]);
    res[2]&=res[1];
    res[1]+=48;
    res[3]=side_by_side(seat_no_1[2],seat_no_2[2]);
    res[3]&=res[2];
    res[2]+=48;
    res[3]+=48;
    fputs(res,out);
	return 0;
}
