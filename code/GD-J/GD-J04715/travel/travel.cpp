#include<bits/stdc++.h>
using namespace std;
string a,s,d,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>d>>f;
	if(a==d){
		printf("%d",1);
	}else{
		printf("%d",0);
	}
	
	if(s[0]==f[0]&&s[1]==f[1]){
		printf("%d",1);
	}else{
		printf("%d",0);
	}
	
	if(s[2]=='A'||s[2]=='C'||s[2]=='B'&&f[2]=='A'||f[2]=='C'||f[2]=='B'){
		printf("%d",1);
	}else if(s[2]=='D'||s[2]=='F'&&f[2]=='D'||f[2]=='F'){
		printf("%d",1);
	}else{
		printf("%d",0);
	}
	
	if(s[2]=='A'){
		if(f[2]=='B'){
			printf("%d",1);
		}else{
			printf("%d",0);
		}
	}
	if(s[2]=='B'){
		if(f[2]=='A'||f[2]=='C'){
			printf("%d",1);
		}else{
			printf("%d",0);
		}
	}
	if(s[2]=='C'){
		if(f[2]=='B'){
			printf("%d",1);
		}else{
			printf("%d",0);
		}
	}
	if(s[2]=='D'){
		if(f[2]=='F'){
			printf("%d",1);
		}else{
			printf("%d",0);
		}
	}
	if(s[2]=='F'){
		if(f[2]=='D'){
			printf("%d",1);
		}else{
			printf("%d",0);
		}
	}
	return 0;
} 
