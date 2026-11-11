#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		printf("1");
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			printf("1");
			if(s1[2]=='D' && s2[2]=='F'){
				printf("11");
				return 0;
		    }
		    else if(s1[2]=='F' && s2[2]=='D'){
				printf("11");
				return 0;
		    }
		    else if(s1[2]=='A' && s2[2]=='B'){
				printf("11");
				return 0;
		    }
		    else if(s1[2]=='B' && s2[2]=='A'){
				printf("11");
				return 0;
		    }		
		    else if(s1[2]=='C' && s2[2]=='B'){
				printf("11");
				return 0;
		    }
		    else if(s1[2]=='B' && s2[2]=='C'){
				printf("11");
				return 0;
		    }		
		    else if(s1[2]=='A' && s2[2]=='C'){
				printf("10");
				return 0;
		    }
		    else if(s1[2]=='C' && s2[2]=='A'){
				printf("10");
				return 0;
		    }	
		    else{
				printf("00");
				return 0;
		    }	
	    }	
	    else{
			printf("000");
			return 0;
	    }	
    }	
    else if(c1!=c2){
		printf("0000");
		return 0;
    }	
	return 0;	
}
