#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	string s3,s4;
	cin>>c1>>s1>>s3>>c2>>s2>>s4;
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
	if((s3[0]>='A'&&s3[0]<='C'&&s4[0]>='A'&&s4[0]<='C')||(s3[0]>='D'&&s3[0]<='F'&&s4[0]>='D'&&s4[0]<='F')){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(s3[0]>='A'&&s3[0]<='C'&&s4[0]>='A'&&s4[0]<='C'){
		if(abs(s3[0]-'A'-(s4[0]-'A'))==1){
			cout<<1;
		}
		else cout<<0;
	}
	else if(s3[0]>='D'&&s3[0]<='F'&&s4[0]>='D'&&s4[0]<='F'){
		if(abs(s3[0]-'A'-(s4[0]-'A'))==2){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		cout<<0;
	}
	return 0;
}

