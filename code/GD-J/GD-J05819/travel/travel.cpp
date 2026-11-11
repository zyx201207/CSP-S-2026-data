#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<"\n";
	}else{
		char s11=s1[0],s12=s1[1];
		char s21=s1[0],s22=s1[1];
		if(s11!=s21 || s12!=s22){
			cout<<"1000"<<"\n";
		}else{
			char a = s1[2],b = s2[2];
			if((a<='C'&&b>='D') || (a>='D'&&b<='C')){
				cout<<"1100"<<"\n";
			}else{
				if(a+1==b || b+1==a){
					cout<<"1111"<<"\n";
				}else{
					cout<<"1110"<<"\n";
				}
			}
		}
	}
	
	return 0;
}
