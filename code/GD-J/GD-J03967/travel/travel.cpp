#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char s12,s22;
	cin>>c1>>s1>>c2>>s2;
	int c11=0,s11=0,c21=0,s21=0;
	for(int i=0;i<2;i++){
		c11+=(c1[i]-'0')*pow(10,1-i);
	}
	for(int i=0;i<2;i++){
		c21+=(c2[i]-'0')*pow(10,1-i);
	}
	for(int i=0;i<2;i++){
		s11+=(s1[i]-'0')*pow(10,1-i);
	}
	for(int i=0;i<2;i++){
		s21+=(s2[i]-'0')*pow(10,1-i);
	}
	s12=s1[2];
	s22=s2[2];
	if(c11==c21){
		cout<<1;
		if(s11==s21){
			cout<<1;
			if(s12>='A'&&s22>='A'){
				if(s12<='C'&&s22<='C'){
					cout<<1;
					if(s12+1==s22&&s12!='C'){
						cout<<1;
						return 0;
					}else if(s12-1==s22&&s12!='D'){
						cout<<1;
						return 0;
					}else{
						cout<<0;
						return 0;
					}
				}
			}
			if(s12>='D'&&s22>='D'){
				cout<<1;
				cout<<1;
				return 0;
			}else{
				cout<<0;
				cout<<0;
				return 0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
			return 0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	return 0;
}
