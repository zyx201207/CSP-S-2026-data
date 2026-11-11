#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string s1,s2;
	cin>>n>>s1>>m>>s2;
	if(n==m){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='D' && s2[2]=='F'){
		cout<<"11";
		return 0;
	}
	int x=s1[2]-'A';
	int y=s2[2]-'A';
	if((x>=3 && y<=2) || (y>=3 && x<=2)){
		cout<<"00";
		return 0;
	}else{
		cout<<1;
	}
	if(x-y==1 || y-x==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}