#include<bits/stdc++.h>
using namespace std;
char c1[11],s1[11],c2[11],s2[11];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
	if(c1[1]!=c2[1]||c1[2]!=c2[2]){
		printf("0000\n");
		return 0;//不在同一车厢 
	}
	else{
		//在同一车厢
		if(s1[1]!=s2[1]||s1[2]!=s2[2]){
			//不在同一排
			printf("1000\n");
		}
		else{
			//在同一排
			int ce1,ce2;
			if(s1[3]=='A'||s1[3]=='B'||s1[3]=='C'){
				ce1=1;
			}
			else ce1=0;
			if(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'){
				ce2=1;
			}
			else ce2=0;
			if(ce1!=ce2){
				//不在同一侧 
				printf("1100\n");
			}
			else{
				//在同一侧
				if(abs(s1[3]-s2[3])==1){
					//相邻
					printf("1111\n");
				}
				else printf("1110\n");
			}
		}
	}
	return 0;
}
