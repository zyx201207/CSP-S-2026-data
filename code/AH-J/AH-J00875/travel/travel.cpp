#include<bits/stdc++.h>
using namespace std;
string s[10],a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	if(s[1]==s[3]){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	a+=s[2][0];
	a+=s[2][1];
	b+=s[4][0];
	b+=s[4][1];
	if(a==b){
		cout<<1;
	}else{
		 cout<<0<<0<<0;
		 return 0;
	 }
		if(s[2][2]>='A'&&s[2][2]<='C'){
			if(s[4][2]>='A'&&s[4][2]<='C'){
				cout<<1;
			}else{
				cout<<0<<0;
				return 0;
			}
		}else if(s[2][2]=='D'||s[2][2]=='F'){
			if(s[4][2]=='D'||s[4][2]=='F'){
				cout<<1;
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0;
			return 0;
		}
	if(s[2][2]-s[4][2]==1||s[4][2]-s[2][2]==1){
		cout<<1;		
	}else{
		cout<<0<<0;
		return 0;
	}	
	return 0;
}
