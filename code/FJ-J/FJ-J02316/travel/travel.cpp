#include<stdio.h> 
#include<iostream>
using namespace std;
string c1,s1,c2,s2;
long long a,b,x1,y1,x2,y2,xx,yy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-'0')*10+c1[1]-'0';
	b=(c2[0]-'0')*10+c2[1]-'0';
	x1=(s1[0]-'0')*10+s1[1]-'0';
	x2=(s2[0]-'0')*10+s2[1]-'0';
	y1=s1[2]-'A';
	if(y1==5){
		y1--;
	}
	y2=s2[2]-'A';
	if(y2==5){
		y2--;
	}
	if(a==b){
		printf("1");
		if(x1==x2){
			printf("1");
			if((y1>=0&&y1<=2&&y2>=0&&y2<=2)||(y1>=3&&y1<=4&&y2>=3&&y2<=4)){
				printf("1");
			}else{
				printf("0");
			}
		}else{
			printf("00");
		}
	}else{
		printf("000");
	}
	xx=max(x1,x2)-min(x1,x2);
	yy=max(y1,y2)-min(y1,y2);
	if(xx==1&&yy==0){
		printf("1");
	}else if(xx==0&&yy==1){
		if(max(y1,y2)!=3&&min(y1,y2)!=2){
			printf("1");
		}else{
			printf("0"); 
		}
	}else{
		printf("0");
	}
	return 0;
}
