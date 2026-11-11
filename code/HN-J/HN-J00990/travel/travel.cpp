#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool a=0,b=0,c=0,d=0;
int main(){
//    freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	ll cnt1=0;
	for(ll i=1;i<=2;i++){
		if(c1[i]==c2[i]){
			cnt1++; 
		}
	}
	if(cnt1==2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		cout<<1;
	}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		cout<<1;
	}else if(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}
/*
DZD NB!
*/ 
