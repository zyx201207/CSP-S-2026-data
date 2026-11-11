#include <iostream>
using namespace std;
int sol1,sol2;
char ld1,ld2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<(int)s1.size();i++){
		if(s1[i]>='0' && s1[i]<='9'){
			sol1=sol1*10+s1[i]-'0';
		}
		if(s1[i]>='A' && s1[i]<='Z'){
			ld1=s1[i];
		}
	}
	for(int i=0;i<(int)s2.size();i++){
		if(s2[i]>='0' && s2[i]<='9'){
			sol2=sol2*10+s2[i]-'0';
		}
		if(s1[i]>='A' && s1[i]<='Z'){
			ld2=s2[i];
		}
	}
	if(sol1==sol2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(ld1>='A' && ld1<='C'){
		if(ld2>='A' && ld2<='C'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(ld2>='D' && ld2<='F'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if((char)(ld1+1)==(char)(ld2) || (char)(ld1-1)==(char)(ld2)){
		cout<<1;
	}
	else{
		if((ld1=='D' && ld2=='F') || (ld1=='F' && ld2=='D'))cout<<1;
		else cout<<0;
	}
	return 0;
} 
