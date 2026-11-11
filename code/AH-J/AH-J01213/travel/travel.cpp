/*
Writer:AH-J01213
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
char a,b,c,d,e,f,g,h,i,j; 
int box1,box2,pi1,pi2,side1,side2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	a=getchar();
	b=getchar();
	box1=(a-'0')*10+(b-'0');
	getchar();
	c=getchar();
	d=getchar();
	e=getchar();
	pi1=(c-'0')*10+(d-'0');
	if(e=='A'||e=='B'||e=='C'){
		side1=0;
	}
	else{
		side1=1;
	}
	getchar();
	f=getchar();
	g=getchar();
	box2=(f-'0')*10+(g-'0');
	getchar();
	h=getchar();
	i=getchar();
	j=getchar();
	pi2=(h-'0')*10+(i-'0');
	if(j=='A'||j=='B'||j=='C'){
		side2=0;
	}
	else{
		side2=1;
	}
	if(box1==box2){
		printf("1");
		if(pi1==pi2){
			printf("1");
			if(side1==side2){
				printf("1");
				if((e=='A'&&j=='B')||(e=='B'&&(j=='A'||j=='C'))||(e=='C'&&j=='B')||(e=='D'&&j=='F')||(e=='F'&&j=='D')){
					printf("1");
					return 0;
				}
				else{
					printf("0");
					return 0;
				}
			}
			else{
				printf("00");
				return 0;
			}
		}
		else{
			printf("000");
			return 0;
		}
	}
	else{
		printf("0000");
		return 0;
	}
	return 0;
}

