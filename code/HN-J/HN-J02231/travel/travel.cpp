#include<bits/stdc++.h>
using namespace std;
int main(){
	string x1,x2,y1,y2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2>>y1>>y2;
	if(x1==y1){
		printf("1");
		int t=(x2[0]-'0')*10+(x2[1]-'0');
		int f=(y2[0]-'0')*10+(y2[1]-'0');
		if(t==f){
			printf("1");
			char v=x2[2];
			char w=y2[2];
			if((v<='C'&&w<='C')||(v>'C'&&w>'C')){
				printf("1");
				if(((v+1)==w||(v-1)==w)){
					printf("1");
				}
				else if((v=='D'&&w=='F')||(v=='F'&&w=='D')){
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
