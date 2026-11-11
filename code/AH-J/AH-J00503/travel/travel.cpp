#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	scanf("%d ",&c1);
	cin>>s1;
	scanf("%d ",&c2);
	cin>>s2;
	if(c1!=c2){
		printf("0000");
		return 0;
	}else{
		printf("1");
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C')){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	if(s1[2]=='D' || s2[2]=='D' || abs(s1[2]-s2[2])==1){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}
