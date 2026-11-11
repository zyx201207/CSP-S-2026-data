#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	int d=0;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s1[2]=='C' && s2[2]=='D'){
		d++;
	}if(s1[2]=='D' && s2[2]=='C'){
		d++;
	}if(d==0){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(max(s1[2],s2[2])-min(s1[2],s2[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}            
