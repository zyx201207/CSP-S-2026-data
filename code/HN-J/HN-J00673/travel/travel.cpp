#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[2]==s2[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2){
		if(s1[2]>='A'||s2[2]>='B'&&s1[2]>='A'||s2[2]>='C'&&s1[2]>='B'||s2[2]>='C'&&s1[2]>='D'||s2[2]>='F'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}
