#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a1,a2;
	string s1,s2;
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2){
		printf("%d",1);
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("%d",1);
			if(s1[0]==s2[0]&&s1[1]==s2[1]&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D')){
				printf("%d",1);
				if(abs(int(s1[2])-int(s2[2]))==1||s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'){
					printf("%d",1);
				}
				else{
					printf("%d",0);	
				}
			}
			else{
				printf("%d%d",0,0);	
			}
	}
	else{
		printf("%d%d%d",0,0,0);	
	}
	}
	else{
		printf("%d%d%d%d",0,0,0,0);	
	}
	
	
}
