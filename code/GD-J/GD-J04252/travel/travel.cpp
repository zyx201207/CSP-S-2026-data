#include <cstdio>
#include <cmath>

char a11[4], a22[4], b11[4], b22[4];
int a, b, c, d;
int main(){
	//rp++
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", a11, a22, b11, b22);
	sscanf(a11, "%d", &a);
	sscanf(b11, "%d", &b);
	if(a == b){
		printf("1");
		if(a22[0] == b22[0] && a22[1] == b22[1]){
			printf("1");
			if(a22[2] <= 'C' && b22[2] <= 'C'){
				printf("1");
				if(a22[2] == 'B' || b22[2] == 'B')	printf("1");
				else	printf("0");
			}
			else if(a22[2] >= 'D' && b22[2] >= 'D')	printf("11");
			else	printf("00");
		}
		else	printf("000");
	}
	else	printf("0000");
	return 0;
}	//xw
