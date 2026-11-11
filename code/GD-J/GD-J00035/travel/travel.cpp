#include<bits/stdc++.h>
using namespace std;
string rx,ry,cx,cy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rx>>ry>>cx>>cy;
	if(rx==cx){
		printf("1");
		if(ry[0]==cy[0]&&ry[1]==cy[1]){
			printf("1");
			if(((ry[2]=='A'||ry[2]=='B'||ry[2]=='C')&&(cy[2]=='A'||cy[2]=='B'||cy[2]=='C'))||((ry[2]=='D'||ry[2]=='F')&&(cy[2]=='D'||cy[2]=='F'))){
				printf("1");
				if(((ry[2]=='A'||ry[2]=='B')&&(cy[2]=='A'||cy[2]=='B'))||((ry[2]=='C'||ry[2]=='B')&&(cy[2]=='C'||cy[2]=='B'))||((ry[2]=='D'||ry[2]=='F')&&(cy[2]=='D'||cy[2]=='F'))){
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
	return 0;
} 
