#include<bits/stdc++.h>
using namespace std;

bool check(char x,char y){
	return (x<='C')&&(y<='C')||(x>='D')&&(y>='D');
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,s1,c2,s2;
	char cc1,cc2;
	scanf("%d %d%c %d %d%c",&c1,&s1,&cc1,&c2,&s2,&cc2);
	printf(
		"%d%d%d%d",
		c1==c2,
		(c1==c2)&&(s1==s2),
		(c1==c2)&&(s1==s2)&&check(cc1,cc2),
		(c1==c2)&&(s1==s2)&&check(cc1,cc2)&&(abs(cc1-cc2)==1)
	);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
