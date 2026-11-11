#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f(char a,char b){
		if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
			return 1;
		}else if(a>='D'&&a<='F'&&b>='D'&&b<='F'){
			return 1;
		}else{
			return 0;	
		}
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(f(s1[2],s2[2])==1){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
