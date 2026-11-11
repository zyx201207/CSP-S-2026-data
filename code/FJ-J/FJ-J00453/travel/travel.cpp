#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2){
		cout<<"0000";
		return 0; 
	}cout<<1;
	if(!(c1[0]==c2[0]&&c1[1]==c2[1])){
		cout<<"000";
		return 0;
	}cout<<1;
	if(c1[2]>='A'&&c1[2]<='C'&&c2[2]>='A'&&c2[2]<='C'||c1[2]>='D'&&c1[2]<='F'&&c2[2]>='D'&&c2[2]<='F'){
		cout<<1;
		if(c1[2]=='D'&&c2[2]=='F'||c1[2]=='F'&&c2[2]=='D'||c1[2]==(c2[2]+1)||c2[2]==c1[2]+1){
			cout<<1;
			return 0;	
		}cout<<0;
		return 0;
	}cout<<"00";
	return 0;
} 
