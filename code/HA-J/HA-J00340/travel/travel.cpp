#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]-'0'==c2[0]-'0'&&c1[1]-'0'==c2[1]-'0'){
		cout<<1;
	}else{
		a=false;
		cout<<0;
	}
	if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0'&&a){
		cout<<1;
	}else{
		a=false;
		cout<<0;
	}if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'&&a){
		cout<<1;
	}else if(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'&&a){
		cout<<1;
	}else{
		a=false;
		cout<<0;
	}
	if(a&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
