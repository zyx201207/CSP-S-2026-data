#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a+='1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a+='1';
	}else{
		cout<<"1000";
		return 0;
	}
	char b=s1[2];
	char d=s2[2];
	bool e = (b>='D'&&d>='D')||(b<='C'&&d<='C');
	if(e){
		a+='1';
	}else{
		cout<<"1100";
		return 0;
	}
	if(b-d==1||d-b==1){
		a+='1';
	}else{
		cout<<"1110";
		return 0;
	}
	cout<<a;
	return 0;
}
