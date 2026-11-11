#include<bits/stdc++.h>
using namespace std;
string c1,s1,c_,s_;
char c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c_>>s_;
	if(c1==c_){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s_[0]&&s1[1]==s_[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	c=s1[2];
	s=s_[2];
	if(c=='A'||c=='B'||c=='C'){
		if(s=='A'||s=='B'||s=='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(s=='F'||s=='D'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if((c=='D'&&s=='C')||(c=='C'&&s=='D')){
		cout<<0;
	}else if(max(c,s)-min(c,s)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
