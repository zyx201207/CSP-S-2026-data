#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}else {
		cout<<"0000";
		return 0;
	}
	char c1,c2,c3,c4;
	c1=s2[0];
	c2=s2[1];
	c3=s4[0];
	c4=s4[1];
	if(c1==c3&&c2==c4){
		cout<<1;
		
	}else{
		cout<<"000";
		return 0;
	}
		
	char c5,c6;
	c5=s2[2];
	c6=s4[2];
	if(((c5=='A'||c5=='B'||c5=='C')&&(c6=='A'||c6=='B'||c6=='C'))||((c5=='D'||c5=='F')&&(c6=='D'||c6=='F'))){
		cout<<1;
	}else {
		cout<<"00";
		return 0;
	}
	if(c5=='A'){
		if(c6=='B'){
			cout<<1;
		}else cout<<0;
	}else if(c5=='B'){
		if(c6=='A'||c6=='C'){
			cout<<1;
		}else cout<<0;
	}else if(c5=='C'){
		if(c6=='B'){
			cout<<1;
		}else cout<<0;
	}else if(c5=='D'){
		if(c6=='F'){
			cout<<1;
		}else cout<<0;
	}else if(c5=='F'){
		if(c6=='D'){
			cout<<1;
		}else cout<<0;
	}
	return 0;
}
