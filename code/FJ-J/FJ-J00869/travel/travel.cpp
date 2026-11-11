#include <cstdio> 
using namespace std;

char s1[5], s2[5], s3[5], s4[5];
int check[4]={0, 0, 0, 0};

void output(){
	for(int i=0;i<4;i++) {
		printf("%d", check[i]);
	}
	return ;
}

int main(){
	freopen("travel.in", "r", stdin) ;
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", s1, s2, s3, s4);
	if(s1[0] == s3[0] && s1[1] == s3[1]){
		check[0]=1;
	}
	else{
		output();
		return 0;	
	} 
	
	if(s2[0] == s4[0] && s2[1] == s4[1]){
		check[1]=1;
	}
	else{
		output();
		return 0;	
	} 
	
	if((s2[2] < 'D' && s4[2] < 'D') || (s2[2] > 'C' && s4[2] >'C')){
		check[2]=1;
	}
	else{
		output();
		return 0;	
	}
	
	if(s2[2]+1 == s4[2] || s4[2]+1 == s2[2]){
		check[3]=1;
	}
	output();
	return 0;
}
