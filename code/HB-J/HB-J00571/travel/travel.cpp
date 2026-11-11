#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a==c){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}
	if(b[0]==d[0] && b[1]==d[1]){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if(b[2]=='A'){
		if(d[2]=='B' || d[2]=='C'){
			printf("1");
		}else{
			printf("00");
			return 0;
		}
	}else if(b[2]=='B'){
		if(d[2]=='A' || d[2]=='C'){
			printf("1");
		}else{
			printf("00");
			return 0;
		}
	}else if(b[2]=='C'){
		if(d[2]=='A' || d[2]=='B'){
			printf("1");
		}else{
			printf("00");
			return 0;
		}
	}else if(b[2]=='D'){
		if(d[2]=='F'){
			printf("1");
		}else{
			printf("00");
			return 0;
		}
	}else if(b[2]=='F'){
		if(d[2]=='D'){
			printf("1");
		}else{
			printf("00");
			return 0;
		}
	}
	if(b[2]=='A'){
		if(d[2]=='B'){
			printf("1");
		}else{
			printf("0");
			return 0;
		}
	}else if(b[2]=='B'){
		if(d[2]=='A' || d[2]=='C'){
			printf("1");
		}else{
			printf("0");
			return 0;
		}
	}else if(b[2]=='C'){
		if(d[2]=='B'){
			printf("1");
		}else{
			printf("0");
			return 0;
		}
	}else if(b[2]=='D'){
		if(d[2]=='F'){
			printf("1");
		}else{
			printf("0");
			return 0;
		}
	}else if(b[2]=='F'){
		if(d[2]=='D'){
			printf("1");
		}else{
			printf("0");
			return 0;
		}
	}
	return 0;
}
