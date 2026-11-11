#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w".stdout);
	int c1,s11,c2,s22;
	char s1,s2;
	cin>>c1>>s11>>s1>>c2>>s22>>s2;
	if(c1==c2){
		cout<<'1';
	}else{
		cout<<'0000';
		return 0;
	}
	if(s11==s22){
		cout<<'1';
	}else{
		cout<<'000';
	}
	if(s1=='A' || s1=='B' || s1=='C'){
		if(s2=='A' || s2=='B' || s2=='C'){
			cout<<'1';
		}else{
			cout<<'00';
		}
	}else{
		if(s1=='F' || s1=='D'){
			if(s2=='F' || s2=='D'){
				cout<<'1';
			}else{
				cout<<'00';
			}
		}
	}
	if(s1!='C' || s1!='D'){
		if(s2!='C' || s2!='D'){
			if(s1+1==s2 || s1-1==s2){
				cout<<'1';
			}else{
				cout<<'0';
			}
		}
	}
	return 0;
}
