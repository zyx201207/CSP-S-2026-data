#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1 + 1,s1 + 1,c2 + 1,s2 + 1);
	if(c1[1] == c2[1] && c1[2] == c2[2]){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}
	if(s1[1] == s2[1] && s1[2] == s2[2]){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if((s1[3] == 'D' && s2[3] == 'F') || (s1[3] == 'F' && s2[3] == 'D')){
		printf("1");
	}else{
		bool ok = false;
		for(char i = 'A';i <= 'C';i++){
			for(char j = i + 1;j <= 'C';j++){
				if((s1[3] == i && s2[3] == j) || (s1[3] == j && s2[3] == i)){
					ok = true;
					break;
				}
			}
		}
		if(ok)
			printf("1");
		else{
			printf("00");
			return 0;
		}
	}
	bool o = false;
	if(s1[3] > 'C' && s2[3] > 'C'){
		printf("1");
	}else{
		if(abs(s1[3] - s2[3]) == 1)
			printf("1");
		else{
			printf("0");
		}
	}
}
