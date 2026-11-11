#include<bits/stdc++.h>
using namespace std;
string s1,s2,a,b;
bool f(){
	return a==b;
}
bool f1(){
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		return 1;
	}return 0;
}bool f2(){
	if((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D')){
		return 1;
	}else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		return 1;
	}return 0;
}bool f3(){
	if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'){
		return 1;
	}else if(s1[2]=='A'&&s2[2]=='B')return 1;
	else if(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A')){
		return 1;
	}else if(s1[2]=='C'&&s2[2]=='B')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>a>>s1>>b>>s2;
	if(f())cout<<1;
	else cout<<0;
	if(f1()&&f()){
		cout<<1;
	}else cout<<0;
	if(f2()&&f1()&&f())cout<<1;
	else cout<<0;
	if(f3()&&f2()&&f1()&&f())cout<<1;
	else cout<<0;
	return 0;
}

