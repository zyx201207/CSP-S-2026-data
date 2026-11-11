#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);		
	string s1,s2,s11,s22;
	cin>>s1>>s11>>s2>>s22;
	if(s1==s2){
		cout<<"1"<<endl;
	}else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(s11[0]==s22[0]&&s11[1]==s22[1]){
		cout<<"1"<<endl;
	}else{
		cout<<"000"<<endl;
		return 0;
	}
	if(s11[0]==s22[0]&&s11[1]==s22[1]&&((s11[2]=='A'&&s22[2]=='B')||(s11[2]=='A'&&s22[2]=='C')||(s11[2]=='B'&&s22[2]=='A')||(s11[2]=='B'&&s22[2]=='C')||(s11[2]=='C'&&s22[2]=='A')||(s11[2]=='C'&&s22[2]=='B')||(s11[2]=='D'&&s22[2]=='F')||(s11[2]=='F'&&s22[2]=='D'))){
		cout<<"1"<<endl;
	}else{
		cout<<"00"<<endl;
		return 0;
	}
	if(s11[0]==s22[0]&&s11[1]==s22[1]&&((s11[2]=='A'&&s22[2]=='B')||(s11[2]=='B'&&s22[2]=='A')||(s11[2]=='B'&&s22[2]=='C')||(s11[2]=='C'&&s22[2]=='B')||(s11[2]=='D'&&s22[2]=='F')||(s11[2]=='F'&&s22[2]=='D'))){
		cout<<"1"<<endl;
	}else{
		cout<<"0"<<endl;
		return 0;
	}
	return 0;
}
