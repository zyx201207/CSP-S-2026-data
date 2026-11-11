#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char s11,s22;
	cin>>c1>>s1>>s11>>c2>>s2>>s22;
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if(s11<='C'&&s22<='C'||s11>='D'&&s22>='D'){
				cout<<"1";
			}else cout<<"0";
		}else cout<<"00";
	}else{
		cout<<"000";
	}
	if((s11=='C'||s22=='C')&&(s11=='D'||s22=='D')){
		cout<<"0";
		return 0;
	}
	if(s1==s2&&(s22-s11==1||s11-s22==1))cout<<"1";
	else cout<<"0";
	return 0;
} 
