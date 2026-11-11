#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(s1[2]=='F') s1[2]='E';
	if(s2[2]=='F') s2[2]='E';
	if(c1==c2){
	cout<<1;	
	}else{
	cout<<"0000";
	return 0;	
	}
	 
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
	cout<<1;
	}else cout<<0;
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
	if(((int)s1[2]<=67&&(int)s2[2]<=67)||((int)s1[2]>=68&&(int)s2[2]>=68)){
		cout<<1;
	}else cout<<0;
	}else cout<<0;	
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
	if(((int)s1[2]<=67&&(int)s2[2]<=67)||((int)s1[2]>=68&&(int)s2[2]>=68)){
		if(abs((int)s1[2]-(int)s2[2])==1){
			cout<<1;
		}else cout<<0;
	}else cout<<0;
	}else cout<<0;
	
	return 0;
} 
