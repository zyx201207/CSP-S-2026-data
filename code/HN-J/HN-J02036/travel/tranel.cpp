#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1 == x1){
		printf("1");
		if(r2[0] == x2[0] and r2[1] == x2[1]){
			printf("1");
			if(r2[2] < 'D' and x2[2] < 'D' or r2[2] >= 'D' and x2[2] >= 'D'){
				printf("1");
				int temp = r2[2] - x2[2];
				if(abs(int(temp)) == 1){
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
	}else{
		printf("0000");
	}
	return 0;
}
