#include<bits/stdc++.h>
using namespace std;
#define File(x) freopen(x".in" , "r" , stdin);freopen(x".out" , "w" , stdout)
int num1 , id1 , num2 , id2;
char ch1 , ch2; 
//ºì 
signed main(){
	File("travel");
	scanf("%d %d%c %d %d%c" , &num1 , &id1 , &ch1 , &num2 , &id2 , &ch2);
	if(ch1 > ch2){
		swap(ch1 , ch2);
	}
	if(num1 != num2){
		puts("0000");
		return 0;
	}else if(id1 != id2){
		puts("1000");
		return 0;
	}
	printf("11");
	if(ch1 == 'A' && (ch2 == 'B' || ch2 == 'C') || ch1 == 'B' && ch2 == 'C' || ch1 == 'D' && ch2 == 'E'){
		putchar('1');
		printf("%d\n" , (ch1 != 'A' || ch2 != 'C'));
		
	}else{
		puts("00");
	}
	return 0;
}
//100
