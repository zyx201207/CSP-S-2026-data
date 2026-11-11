#include<bits/stdc++.h>
using namespace std;
char a[10],b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
    scanf("%c%c %c%c%c %c%c %c%c%c",&a[1],&a[2],&a[3],&a[4],&a[5],&b[1],&b[2],&b[3],&b[4],&b[5]);
    
    int ca=int(a[1]-'0')*10+int(a[2]-'0');
    int cb=int(b[1]-'0')*10+int(b[2]-'0');
    if(ca==cb) printf("1");
    else {
		printf("0000");
		return 0;
	}

    int pa=int(a[3]-'0')*10+int(a[4]-'0');
    int pb=int(b[3]-'0')*10+int(b[4]-'0');
    if(pa==pb) printf("1");
    else {
		printf("000");
		return 0;
	}
    
    if((a[5]<='C'&&b[5]<='C')||(a[5]>='D'&&b[5]>='D')){
		printf("1");
		if((a[5]=='A'&&b[5]=='B')||(b[5]=='A'&&a[5]=='B')||(a[5]=='B'&&b[5]=='C')||(b[5]=='B'&&a[5]=='C')||(a[5]=='D'&&b[5]=='F')||(b[5]=='D'&&a[5]=='F'))
			printf("1");
		else
			printf("0");
	}else{
		printf("00");
		return 0;
	}
    return 0;
}
