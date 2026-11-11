#include <iostream>
using namespace std;

string c1,s1,c2,s2;
bool b1,b2,b3,b4;

bool chack1(char c1,char c2){
	if(b2){
		if(c1=='D'){
			if(c2=='A'||c2=='B'||c2=='C'){
				return 0;
			}
	}else if(c1=='F'){
			if(c2=='A'||c2=='B'||c2=='C'){
				return 0;
			}
		}else 	if(c2=='D'){
			if(c1=='A'||c1=='B'||c1=='C'){
				return 0;
			}
	}else if(c2=='F'){
			if(c1='A'||c1=='B'||c1=='C'){
				return 0;
			}
		}
	}
	
	return 1;
}

bool chack2(char c1,char c2){
	if(b3){
		int tot=c1-c2;
		if(abs(tot)==1){
			return 1;
		}else{
			return 0;
		}
	}
}

int main() {
	freopen("travel.in","w",stdin);
	freopen("traver.out","r",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		b1=1;
	}else{
		b1=0;
	}
	
	if(b1&&(s1[0]==s2[0]&&s1[1]==s2[1])){
		b2=1;
	}else{
		b2=0;
	}
	
	if(b1&&b2&&(chack1(s1[2],s2[2]))){
		b3=1;
	}else{
		b3=0;
	}
	
	if(b3&&chack2(s1[2],s2[2])){
		b4=1;
	}else{
		b4=0;
	}
	
	cout<<b1<<b2<<b3<<b4;
	
	return 0;
}

