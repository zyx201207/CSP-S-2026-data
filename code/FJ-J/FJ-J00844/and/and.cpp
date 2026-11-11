#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a,b;
int q,w;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	for(long long i=0;i<=1;i++){
		a+=s1[i];
		b+=s2[i];		
	}
	if(a==b){
		cout<<1;
		q=1;
	}
	else{
		cout<<0;
	}
	if(s1[2]==s2[2]){
		cout<<1;
		w=1;
	}
	else{
		cout<<0;
	}
	if((s1[2]=='A'&&s2[2]=='B')|| (s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
} 
