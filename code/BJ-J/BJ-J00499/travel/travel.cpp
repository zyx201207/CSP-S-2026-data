#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1o,c2o,s1o,s2o,ans;
	freopen("travel.in","r","stdin")
	freopen("travel.out","w","stdout")
	
	cin>>c1o>>s1o>>c2o>>s2o;
	if(c1o[1]==c2o[1]&&c1o[2]==c2o[2]){
		cout<<1;
		if(s1o[0]==s2o[0]&&s1o[1]==s2o[1]){
			cout<<1;
			if(s1o[2]=='A'||s1o[2]=='B'||s1o[2]=='C'){
		if(s2o[2]=='A'||s2o[2]=='B'||s2o[2]=='C'){
			cout<<1;
			if(s1o[2]=='B'||s2o[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0;
		}
	}else{
		if(s2o[2]=='D'||s2o[2]=='E'){
			cout<<1<<1;
		}else{
			cout<<0<<0;
		}
	}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
	
	
}
