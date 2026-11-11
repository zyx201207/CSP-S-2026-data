#include<bits/stdc++.h>

using namespace std;

string s1,s2,d1,d2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>d1>>s2>>d2;
	if(s1==s2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(d1[0]==d2[0] && d1[1]==d2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(d1[2]=='A' || d1[2]=='B' || d1[2]=='C'){
		if(d2[2]=='A' || d2[2]=='B' || d2[2]=='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(d1[2]=='D' || d1[2]=='F'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(d1[2]=='A' && d2[2]=='B' || d1[2]=='B' && d2[2]=='A'){
		cout<<1; 
	}else if(d1[2]=='C' && d2[2]=='B' || d1[2]=='B' && d2[2]=='C'){
		cout<<1;
	}else if(d1[2]=='D' && d2[2]=='F' || d1[2]=='F' && d2[2]=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	return 0;
} 
