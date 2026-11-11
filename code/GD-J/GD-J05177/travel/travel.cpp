#include<bits/stdc++.h>
using namespace std;
#define long long ll
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char aa[4],bb[4];
	int a,b;
	scanf("%d",&a);
	scanf("%s",&aa);
	scanf("%d",&b);
	scanf("%s",&bb);
	if(a==b){
		printf("1");
	}
	else{
		printf("0000");
		return 0;
	}
	if(aa[0]==bb[0]&&aa[1]==bb[1]){
		printf("1");
	}
	else{
		printf("000");
		return 0;
	}
	if((aa[2]=='A'&&(bb[2]=='B'||bb[2]=='C'))||(aa[2]=='B'&&(bb[2]=='A'||bb[2]=='C'))||(aa[2]=='C'&&(bb[2]=='B'||bb[2]=='A'))||(aa[2]=='D'&&bb[2]=='F')||(aa[2]=='F'&&bb[2]=='D')){
		printf("1");
	}
	else{
		printf("00");
		return 0;
	}
	if(aa[2]-1==bb[2]||aa[2]+1==bb[2]||bb[2]+1==aa[2]||bb[2]-1==aa[2]){
		printf("1");
		return 0;
	}
	else{
		printf("0");
		return 0;
	}
} 
