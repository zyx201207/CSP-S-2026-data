#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char s3,s4;
	cin>>c1>>s1;
	cin>>s3;
	cin>>c2>>s2;
	cin>>s4;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1==s2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s3=='A'||s3=='B'||s3=='C'){
		if(s4=='A'||s4=='B'||s4=='C'){
			cout<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	else{
		if(s4=='D'||s4=='F'){
			cout<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	if(s3+1==s4||s4+1==s3){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
