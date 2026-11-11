#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,t1,s2,t2;
	cin>>s1>>t1>>s2>>t2;
	if(s1==s2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(t1[0]==t2[0]&&t1[1]==t2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(t1[2]=='A'||t1[2]=='B'||t1[2]=='C'){
		if(t2[2]=='A'||t2[2]=='B'||t2[2]=='C'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(t1[2]=='D'||t1[2]=='F'){
		if(t2[2]=='D'||t2[2]=='F'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(t1[2]=='A'||t1[2]=='B'||t1[2]=='C'&&t2[2]=='A'||t2[2]=='B'||t2[2]=='C'){
		if(t2[2]+1==t1[2]||t2[2]-1==t1[2]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(t1[2]=='D'||t1[2]=='F'&&t2[2]=='D'||t2[2]=='F'){
		if(t2[2]==t1[2]+2||t2[2]==t1[2]-2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
