#include<bits/stdc++.h>
using namespace std;

int n,m;
char c_one[5],c_two[5];

//rp++
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%s%d%s",&n,c_one,&m,&c_two);
	bool a = 0,b = 0,c = 0,d = 0;
	if(n == m){
		printf("1");
		a = 1;
	}
	else{
		printf("0");
	}	
	
	
	if((c_one[1] == c_two[1]) && a){
		printf("1");
		b = 1;
	}
	else{
		printf("0");
	}
	
	
	
	if(((c_one[2] == 'A' && c_two[2] == 'E') || (c_one[2] == 'B' && c_two[2] == 'E') || (c_one[2] == 'C' && c_two[2] == 'E') || (c_one[2] == 'C' && c_two[2] == 'F') || (c_one[2] == 'B' && c_two[2] == 'F') ||(c_one[2] == 'A' && c_two[2] == 'F')) || !b){
		printf("0");
	}
	else{
		printf("1");
		c = 1;
	}
	
	
	if(((c_one[2] == 'A' && c_two[2] == 'B') || (c_one[2] == 'A' && c_two[2] == 'B')) && c) {
		printf("1");
	}
	else if(((c_one[2] == 'B' && c_two[2] == 'C') || (c_one[2] == 'C' && c_two[2] == 'B')) && c){
		printf("1");
	}
	else if(((c_one[2] == 'E' && c_two[2] == 'F') || (c_one[2] == 'F' && c_two[2] == 'E')) && c){
		printf("1");
	}
	else{
		printf("0");
	}
	
	return 0;
}