#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	 
	if(c1==c2){
		printf("1");
		if(((s1[0]-'0')*10+s1[1]-'0')==((s2[0]-'0')*10+s2[1]-'0')){
			printf("1");
			char a=s1[2],b=s2[2];
			if(a-'A'<=2&&b-'A'<=2){
				printf("1");
				if(((a-'A')-(b-'A'))==1||((a-'A')-(b-'A'))==-1){
					printf("1");
				}else{
					printf("0");
				}
			}else{ 
				if(a-'A'<=5&&a-'A'>2&&b-'A'<=5&&b-'A'>2){
					printf("1");
					if(((a-'A')-(b-'A'))==2||((a-'A')-(b -'A'))==-2){
						printf("1");
					}else{
						printf("0");
					}
				}else{
					printf("00");
					return 0;
				}
				
			}
			
		}else{
			printf("000");
			return 0;
		}
		
	}else{
		printf("0000");
		return 0;
	}
	
	
	
	//cout<<c1<<' '<<s1<<'\n'<<c2<<' '<<s2;
	
	
	
	return 0;
} 
