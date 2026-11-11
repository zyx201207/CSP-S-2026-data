#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,a,a1;
	cin>>a>>s>>a1>>s1;
	if(a==a1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==s1[0]&&s[1]==s1[1]){
		cout<<1;
	}else {
		cout<<"000";
		return 0;
	}
	if((s[2]>'C'&&s1[2]>'C')||(s[2]<='C'&&s1[2]<='C')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(s[2]+1==s1[2]||s1[2]+1==s[2]){
		cout<<1;
	}else{
		cout<<"0";
	}
	return 0;
}
