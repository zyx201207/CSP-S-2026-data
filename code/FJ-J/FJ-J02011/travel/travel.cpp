#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	if(s1==s3)cout<<"1";
	bool check=true;
	for(int i=0;i<2;i++){
		if(s2[i]!=s4[i]){
			check=false;
			break;
		}
	} 
	if(check)cout<<"1";
	if(!check){
		cout<<"000";
		return 0;
	}
	int a=s2[2],b=s4[2];
	if(min(a,b)<='C'){
		if(max(a,b)>'C'){
			cout<<"00";
			return 0;
		}
		else cout<<"1";
	}
	if(min(a,b)>'C'){
		cout<<"1";
	}
	if(max(a,b)-min(a,b)==1){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
} 
