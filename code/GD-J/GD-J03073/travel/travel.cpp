#include<bits/stdc++.h>
using namespace std;
long long l1,l2,z,x,c;
string s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>l1>>s1>>l2>>s2;
	if(s2[2]>s1[2]){
		swap(s1,s2);
	}
	if(l1==l2){
		cout<<1;
	}
	else{
		cout<<0;
		z=1;
	}
	
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&!z){
		cout<<1;
	}
	else{
		cout<<0;
		x=1;
	}
	
	
	if((s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D')&&!x){
		cout<<1;
	} 
	else{
		cout<<0;
		c=1;
	}
	if((s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D')&&!c){
		cout<<1;
	} 
	else{
		cout<<0;
	}
	
	
	return 0;
}
