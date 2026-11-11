#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char a,b,c,d,f;
	scanf("%d",&c1);
	scanf("%d",&c2);
	scanf("%d",&s1);
	scanf("%d",&s2);
	for(int i = 1;i <= 2;i++)
	if(c1 == c2){
		printf("%d",1);
	}
	if(s1 = s2){
		printf("%d",1);
	}
	//if(a = "A"&&b = "B"||a = "A" && c = "C"||b = "B" && c = "C"||d = "D"&&f = "F"){
		//printf("%d",1);
	//}
	//else if(A = "A"&&B = "B"||B = "B" && C = "C"||D = "D"&&F = "F"){
		//printf("%d\n",1);
	//}
	else{
		printf("%d\n",0);
	}
	return 0;
}
