#include<bits/stdc++.h>
using namespace std;
char c1[20000],s1[20000],c2[20000],s2[20000];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",c1,s1,c2,s2);
	if(s1[2]=='D') s1[2]++;
	if(s2[2]=='D') s2[2]++;
	if(strcmp(c1,c2)==0){
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("1");
			if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'D'&&s2[2]>'D')){
				printf("1");
				if(abs(s1[2]-s2[2])==1){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	return 0;
}
