#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int s11=s1[0]*10+s1[1],s21=s2[0]*10+s2[1];
	if(s11==s21){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
