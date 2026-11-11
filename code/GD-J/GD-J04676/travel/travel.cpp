#include<bits/stdc++.h>
using namespace std;
string c[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i = 1;i <= 4;i++){
		cin >> c[i];
	}
	
	string s1 = c[2],s2 = c[4];
	
	if(c[1] != c[3]){//同一车厢
		printf("0000");
	}else{
		if(s1[0] == s2[0] && s1[1] == s2[1]){//同一排
		 	if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')&&(s2[2] == 'D' || s2[2] == 'F')){
				printf("1100");
			}else if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
				printf("1100");
			}else{
				if(s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1){//相差一 
					printf("1111");
				}else if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')){
					printf("1111");
				}else{
					printf("1110");
				}
			}
		}else{
			printf("1000");
		}
	}
	
	return 0;
} 
