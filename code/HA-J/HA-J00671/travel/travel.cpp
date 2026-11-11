#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

char c1[5],s1[5],c2[5],s2[5];
bool id(char a){
	if(a=='A'||a=='B'||a=='C')return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%s%s%s%s",c1,s1,c2,s2);
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(id(s1[2])==id(s2[2])){
				if(id(s1[2])==1){
					int t1=s1[2]-'A';
					int t2=s2[2]-'A';
					if(abs(t1-t2)==1){
						printf("1111");
					}else{
						printf("1110");
					}
				}else{
					if(s1[2]=='D'&&s2[2]=='F'){
						printf("1111");
					}else if(s1[2]=='F'&&s2[2]=='D'){
						printf("1111");
					}else{
						printf("1110");
					}
				}
			}else{
				printf("1100");
			}
		}else{
			printf("1000");
		}
	}else{
		printf("0000");
	}
	return 0;
}
