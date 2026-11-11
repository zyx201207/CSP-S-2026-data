#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
bool a=false,c=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		printf("%d",1);
		c=true;
	}else{
		printf("%d",0);
	}
	if((s1[0]==s2[0])&&(s1[1]==s2[1])){
		if(c){
			printf("%d",1);
			a=true;
		}else{
			printf("%d",0);
	}
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			if(a==true&&c==true){
				printf("%d",1);
			}else{
				printf("%d",0);
			}
		}
	}
	
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F'){
			if(a==true&&c==true){
				printf("%d",1);
			}else{
				printf("%d",0);
			}
		}
	}
	
	
	if(s1[2]=='A'||s1[2]=='C'){
		if(s2[2]=='B'&&a==true){
				printf("%d",1);
			}else{
				printf("%d",0);
			}
			
	}
	if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C'){
			if(a==true&&c==true){
				printf("%d",1);
			}else{
				printf("%d",0);
			}
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
