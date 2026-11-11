#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int f1=0,f2=0,f3=1,f4=0;
	if(c1==c2){
		f1=1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		f2=1;
	}else{
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='C'&&s2[2]=='D'){
		f3=0;
	}else if(s1[2]=='D'&&s2[2]=='C'){
		f3=0;
	}else{
		if(s1[2]==s2[2]-1||s1[2]==s2[2]+1){
			f4=1;
		}
	}
	
	cout<<f1<<f2<<f3<<f4;
	return 0;
}