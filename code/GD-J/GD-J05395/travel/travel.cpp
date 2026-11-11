#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool check(string s1,strings2){
	if(s1[2]='D'&&s2[2]='F'){
		return 1;
	}
	if(s1[2]='F'&&s2[2]='D'){
		return 1;
	}
	if(s1[2]='A'&&s2[2]='B'||s1[2]='A'&&s2[2]='C'){
		return 1;
	}
	if(s1[2]='B'&&s2[2]='C'||s1[2]='B'&&s2[2]='A'){
		return 1;
	}
	if(s1[2]='C'&&s2[2]='B'||s1[2]='C'&&s2[2]='A'){
		return 1;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		cout<<"0000";
	}else{
		if(a2[0]!=b2[0]||a2[1]!=b2[1]){
			cout<<"1000";
		}else{
			if()
		}
	}
	return 0;
} 
