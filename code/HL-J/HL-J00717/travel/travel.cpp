#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s3;
	string s2,s4,a;
	scanf("%d%s%d%s",&s1,&s2,&s3,&s4);	
	if(s1==s3){
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			if((s2[2]=='D'&&s4[2]=='F')||(s4[2]=='D'&&s2[2]=='F')){
		    	printf("%s","1111");
			}
			else if((s2[2]>='A'&&s2[2]<='C')&&(s4[2]>='A'&&s4[2]<='C')){
			    if((s2[2]=='A'||s4[2]=='B')||(s2[2]=='B'&&s4[2]=='A')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='B')){
			   	    printf("%s","1111");
			    }
			    else{
			   	    printf("%s","1110");
			    }
		    }
		    
		      
		    else{
		    	printf("%s","1100");
			}
		}
		else{
			printf("%s","1000");
		}	
	}
	else{
		printf("%s","0000");
	}
	
	
	return 0;
}