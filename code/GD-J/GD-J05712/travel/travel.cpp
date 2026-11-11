#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		printf("1");
		int a=0,b=0;
		a=(s1[0]-'0')*10+s1[1]-'0';
		b=(s2[0]-'0')*10+s2[1]-'0';
		if(a==b){
			printf("1");
			char x,y;
			x=s1[2];
			y=s2[2];
			if((x>='A' && x<='C' && y>='A' && y<='C')||(x>='D' && x<='F' && y>='D' && y<='F')){
				printf("1");
				if((x=='A' && y=='B')||(x=='B' && y=='A')||(x=='B' && y=='C')||(x=='C' && y=='B')||(x=='D' && y=='F')||(x=='F' && y=='D'))
				{
					printf("1");
				}
				else{
					printf("0");
				}
			}
			else{
				printf("00");
			}
		}
		else{
			printf("000");
		}
	}
	else{
		printf("0000");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
