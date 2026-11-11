#include<bits/stdc++.h>
using namespace std;
char a11,a12,a13,s11,s12,s13;
int a,s,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&a);
	scanf(" %c%c%c",&a11,&a12,&a13);
	scanf("%d",&s);
	scanf(" %c%c%c",&s11,&s12,&s13);
	if(a==s){
		printf("1");
		if(a11==s11&&a12==s12){
			printf("1");
			bool p=0;
			if((a13<'D'&&s13<'D')||(a13>='D'&&s13>='D')){
				p=1;
				printf("1");
				if(abs(a13-s13)==1&&(a13!='C'||s13!='D')&&(a13!='D'||s13!='C'))cout<<1;
				else cout<<0;
			}else printf("00");
		}else printf("000");
	}else printf("0000");
	return 0;
}
