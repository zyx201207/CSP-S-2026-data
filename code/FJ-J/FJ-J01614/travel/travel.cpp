#include <bits/stdc++.h>
using namespace std;
int c,cc,p,pp,n,m;
char s,ss;
int f(char x){
	if ('A'<=x && x<='C')
		return 1;
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    scanf("%d %d%c %d %d%c",&c,&p,&s,&cc,&pp,&ss);
    n = f(s);
    m = f(ss);
    if (c==cc)
    	printf("%d",1);
    else
    	printf("%d",0);
    if (c==cc && p==pp)
    	printf("%d",1);
    else
    	printf("%d",0);
    if (c==cc && p==pp && n==m)
    	printf("%d",1);
    else
    	printf("%d",0);
    if (c==cc && p==pp && n==m){
    	if (n==1 && (s+1==ss || ss+1==s))
    	    printf("%d",1);
    	else if (n==0 && (s+2==ss || ss+2==s))
    		printf("%d",1);
    	else 
    	    printf("%d",0);
	}
    else{
        printf("%d",0);}//100
	return 0;
}

