#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.length();i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	if(c1.length()!=c2.length()){
		cout<<0;
	}else{
		bool f1=0;
		for(int i=0;i<c1.length();i++){
			if(c1[i]!=c2[i]){
				cout<<0;
				f1=1;
			}
		}
		if(f1==0){
			cout<<1;
		}
	}
	bool f2=0;
	for(int i=0;i<s1.length();i++){
		if(isdigit(s1[i])){
			if(s1[i]!=s2[i]){
				cout<<0;
				f2=1;
			}
		}
	}
	if(f2==0){
		cout<<1;
	}
	if(s1[0]!=s1[0]||s1[1]!=s2[1]){
		cout<<0;
	}else if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='D'||s2[2]=='E'){
			cout<<0;
		}else{
			cout<<1;
		}
	}else if(s1[2]=='D'||s1[2]=='E'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			cout<<0;
		}else{
			cout<<1;
		}
	}else if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		if(s1[2]=='D'||s1[2]=='E'){
			cout<<0;
		}else{
			cout<<1;
		}
	}else if(s2[2]=='D'||s2[2]=='E'){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	if(s1[0]!=s1[0]||s1[1]!=s2[1]){
		cout<<0;
	}else if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D')){
		cout<<0;
	}else{
		if(abs(s1[2]-s2[2])==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
