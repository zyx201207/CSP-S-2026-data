#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);  
    scanf("%d",&c1);
    cin>>s1;
    scanf("%d",&c2);
    cin>>s2;
    int k1=s1[2]-'A',k2=s2[2]-'A';
	if(c1==c2){
		printf("1");
	}
	else{
		printf("0000");
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		printf("1");
	}
	else{
		printf("000");
		return 0;
	}
	if((k1<=2&&k2<=2)||(k1>=3&&k2>=3)){
		printf("1");
	}
	else{
		printf("00");
		return 0;
	}
	if(abs(k2-k1)==1){
		printf("1");
	}
	else{
		printf("0");
	}
    return 0;
}
