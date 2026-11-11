#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a(char q,char w){
	if(q>w) swap(q,w);
	if(q=='D'&&w=='F'){
		return 1;
	}
	if(w==q+1){
		return 1;
	}
	return 0;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	 cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	//
	bool bs1,bs2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		bs1=0;
	}else{
		bs1=1;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		bs2=0;
	}else{
		bs2=1;
	}
	//
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&bs1==bs2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&bs1==bs2&&a(s1[2],s2[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
