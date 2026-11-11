#include<bits/stdc++.h>
using namespace std;
char c1[3],c2[4],s1[3],s2[4];
char l[3]={'A','B','C'},r[2]={'D','F'};
bool p,lin;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1,c2,s1,s2);
	for(int i=0;i<2;i++)
		for(int j=0;j<3;j++) {
			if((c2[2]==l[j])&&(s2[2]==r[i]))p=1;
			if((s2[2]==l[j])&&(c2[2]==r[i]))p=1;
		}	
	if((c1[0]!=s1[0])||(c1[1]!=s1[1])){
		printf("0000");
	}		
	else {
		if((c2[0]!=s2[0])||(c2[1]!=s2[1])){
			printf("1000");
		}
		else {
			if(p)
				printf("1100");
			else {
				if(abs(int(c2[2])-int(s2[2]))!=1)
					printf("1110");
				else printf("1111");
			}				
		}
	}		
	return 0;
}
