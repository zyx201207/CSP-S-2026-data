#include <bits/stdc++.h> 
using namespace std;
string s,a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	if(s[0] == s[7] && s[1] == s[8]){ 
		printf("1");
		if(s[4] == s[11] && s[3] == s[10]){
			printf("1");
			if(((s[5] == 'A' || s[5] == 'B' || s[5] == 'C') && (s[12] == 'A' || s[12] == 'B' || s[12] == 'C')) || ((s[5] == 'D' || s[5] == 'F') && (s[12] == 'D' || s[12] == 'F'))){
				printf("1");
				if((s[5] == 'F' && s[12] == 'D') || (s[5] == 'D' && s[12] == 'F') || (s[5] == 'C' && s[12] == 'B') || (s[5] == 'B' && s[12] == 'C') || (s[5] == 'B' && s[12] == 'A') || (s[5] == 'A' && s[12] == 'B')){
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
	}return 0;
}
/*
02 01A 02 01B
1111
02 01C 02 01A
1110
02 01C 02 01D
1100
02 02B 02 01A
1000
02 01A 03 01A
0000
*/
