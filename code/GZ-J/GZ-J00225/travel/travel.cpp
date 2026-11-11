//GZ-J00225 遵义市播州区南白初级中学 项柏源 
#include <bits/stdc++.h>
using namespace std;
char a[20];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    scanf("%s",a+1);
    int a1=(a[1]-'0')*10+(a[2]-'0');
    int b1=(a[8]-'0')*10+(a[9]-'0');
    int a2=(a[4]-'0')*10+(a[5]-'0');
    int b2=(a[11]-'0')*10+(a[12]-'0');
    if(a1==b1){
    	printf("1");
	}
	else{
		printf("0000");
		return 0;
	}
	if(a2==b2){
    	printf("1");
	}
	else{
		printf("000");
		return 0;
	}
	if(((a[6]<'D')&&(a[13]<'D'))||((a[6]>='D')&&(a[13]>='D'))){
    	printf("1");
	}
	else{
		printf("00");
		return 0;
	}
	if((a[6]-a[13]==1)||(a[6]-a[13]==-1)){
		printf("1");
	}
	else{
		printf("0");
	}
    return 0;	
}

