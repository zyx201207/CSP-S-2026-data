#include<cstdio>
char max(char a,char b){
	return (a>b?a:b);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[4],s2[4];
	scanf("%d%s%d%s",&c1,&s1,&c2,&s2);
	if(c1!=c2){
		printf("0000");
		return 0;
	}else{
		printf("1");
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D')){
		printf("00");
		return 0;
	}else{
		printf("1");
	}
	if(max(s1[2],s2[2])-1==s1[2]||max(s1[2],s2[2])-1==s2[2]){
		printf("1");
		return 0;
	}else{
		printf("0");
		return 0;
	}
	return 0;
} 
