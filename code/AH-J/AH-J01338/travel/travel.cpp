#include<bits/stdc++.h>
using namespace std;
int c1;
string s1;
int c2;
string s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	bool ok=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			ok=0;
		}
	}
	if(ok){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>=3&&s2[2]-'A'>=3)){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
		if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
			cout<<0;
			return 0;
		}else{
		    cout<<1;	
		}
	}else{
		if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')){
			cout<<1;	
		}else{
			cout<<0;
		}
	}
	return 0;
} 
