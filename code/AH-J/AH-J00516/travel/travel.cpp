#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a!=b) {
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<"1";
	if((s1[0]-'0')*10+s1[1]==(s2[0]-'0')*10+s2[1]||s1[2]-'A'==s2[2]-'A'){
		cout<<"1";
	}else {
		cout<<"000"<<endl;
		return 0;
	}
	if((s1[2]-'A'<='C'-'A'&&s2[2]-'A'>='D'-'A')||(s2[2]-'A'<='C'-'A'&&s1[2]-'A'>='D'-'A')){
		cout<<"00"<<endl;
		return 0;
	}
	else cout<<"1";
	if(s1[0]*10+s1[1]-s2[0]*10-s2[1]>=-1&&s1[0]*10+s1[1]-s2[0]*10-s2[1]<=1){
		if(s1[2]-s2[2]>=-1&&s1[2]-s2[2]<=1){
			cout<<"1"<<endl;
		}
		else cout<<"0"<<endl;
	}
	else cout<<"0"<<endl;
	return 0;
}
