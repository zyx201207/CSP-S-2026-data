#include<bits/stdc++.h>
using namespace std;
#define qwq(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);

int c1,rw1,c2,rw2;
char i1,i2;

/*
"Simulation has no value to train"
--said by Luogu:@__SeaWave__
*/

//08:30 got problems
//08:40 done T1 

int main(){
	#ifndef off
	qwq("travel");
	#endif
	
	scanf("%d",&c1);
	scanf("%2d%c",&rw1,&i1);
	
	
	scanf("%d",&c2);
	scanf("%2d%c",&rw2,&i2);
	
	#ifdef debug
	printf("%d %d%c %d %d%c\n",c1,rw1,i1,c2,rw2,i2);
	#endif
	
	
	if(c1!=c2){
		puts("0000");return 0;
	}else putchar('1');
	
	if(rw1!=rw2){
		puts("000");return 0;
	}else putchar('1');
	
	if((i1<='C'&&i2<='C')||(i1>'C'&&i2>'C'))putchar('1');
	else{
		puts("00");return 0;
	}
	
	if(i1<='C'&&i2<='C'){
		if(i1-i2==1||i1-i2==-1)putchar('1');
		else putchar('0');
		return 0;
	}else{
		putchar('1');
		return 0;
	}
}