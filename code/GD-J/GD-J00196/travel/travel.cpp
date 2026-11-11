#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string c1,s1,c2,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	} 
	cout<<"1";
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000"<<endl;
		return 0;
	}
	cout<<"1";
	if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>'C'&&s2[2]<='C')){
		cout<<"00"<<endl;
		return 0;
	}
	cout<<"1";
	if(s1[2]<='C'&&s2[2]<='C'){
		if(abs(s1[2]-s2[2])==1){
			cout<<"1"<<endl;
		}
		else
			cout<<"0"<<endl;
	} 
	else{
		if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
			cout<<"1"<<endl;
		}
		else
			cout<<"0"<<endl;
	}
	return 0;
} 
