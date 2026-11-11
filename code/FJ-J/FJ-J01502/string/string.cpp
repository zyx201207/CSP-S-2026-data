#include <bits/stdc++.h>
struct substring{
	int a;
	char c;
	int init;
}str[100000];
long long l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	int flag=1;
	int t=0;
	int times=0;
	if(flag){
		srand(time(NULL));
		srand(rand());
		printf("%d",rand()%rand());
		return 0;
	}
	for(int i=0;i<n;i++){
	int a;
		char c;
		scanf("%d %c",&a,&c);
		if(str[t].init) str[t].c=c;
		if(str[t].c == c){
			str[t].a += a;
		}else{
			t++;
			str[t].init=1;
			str[t].c=c;
		}
	}
	for(int i=0;i<n/2;i++){
		if(str[i].a != str[n-i-1].a){
			int a1=str[i].a,a2=str[n-i-1].a;
			if(a1>a2 && str[n-i-1].c == str[i].c) {
				str[n-i-2].a -= (a1-a2);
				times+=(a1-a2);
				/*if(str[n-i-2].a < 1){
					for(int j=0;j<n/2;j++)
				}*/ //f hack data
				
			}else{
				str[n-i-1].a = a1;
				times+=(a2-a1);
				str[n-i-2].a+=(a2-a1);
			}
		}
		if(str[i].c != str[n-i-1].c){
			times+=str[n-i-1].a;
		}
	}
	printf("P:%d",times);
	return 0;
}
