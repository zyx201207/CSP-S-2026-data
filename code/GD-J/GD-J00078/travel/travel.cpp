#include<bits/stdc++.h>

using namespace std;

int main(){	
	int c1;
	int c2;
	string s1;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&s1==s2){
		return -1;
	}
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	int i = int(s1[0])*10+int(s1[1]);
	int j = int(s2[0])*10+int(s2[1]);
	if(i==j){
		cout<<"1";
	}
	if(i==j){
		if(s1[2]<='c'&&s2[2]>'c'){
			cout<<"0";
		}
		else if(s2[2]<='c'&&s1[2]>'c'){
			cout<<"0";
		}
		else{
			cout<<"1";
		}
	}
	if(i==j&&abs(int(s2[2])-int(s1[2]))==1){
		if(s1[2]<='c' && s2[2]>'c'){
			cout<<"0";
		}
		else if(s2[2]<='c' && s1[2]>'c'){
			cout<<"0";
		}
		else {
			cout<<"1";
		}
		return 0;
	}
}

