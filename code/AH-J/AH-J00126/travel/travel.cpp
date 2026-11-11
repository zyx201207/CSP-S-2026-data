#include <bits/stdc++.h>
using namespace std;
int main(void){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    long long a,b,c,d;
    char ch1,ch2;
    scanf("%lld %2lld%c %lld %2lld%c",&a,&b,&ch1,&c,&d,&ch2);
    if(a!=c)printf("0000");
    else {printf("1");
        if(b!=d)printf("000");
        else {
            printf("1");
            if(ch1<='C'&&ch2>'C'||ch1>'C'&&ch2<='C')printf("00");
            else{
                printf("1");
                if(ch1==ch2+1||ch2==ch1+1||ch1=='D'&&ch2=='F'||ch2=='D'&&ch1=='F')printf("1");
                else printf("0");
            }
        }
    }
	return 0;
}
