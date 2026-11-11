#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
bool check(char x,char y){
	return (x>='A'&&x<='C'&&y>='A'&&y<='C')
	    || ((x=='D'||x=='F')&&(y=='D'||y=='F'));
}
bool check1(char x,char y){
	if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
		if(abs((int)(y-x))==1){
			return 1;
		}
	}
	else{
		return 1;
	}
	return 0;
}
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	ans+='1';
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		ans+='1';
		if(check(s1[2],s2[2])){
			ans+='1';
			if(check1(s1[2],s2[2])){
				ans+='1';
				cout<<ans;
			}
			else{
				ans+='0';
				cout<<ans;
			}
		}
		else{
			ans+='0';
			ans+='0';
			cout<<ans;
		}
	}
	else{
		ans+='0';
		ans+='0';
		ans+='0';
		cout<<ans;
	}
	return 0;
} 
