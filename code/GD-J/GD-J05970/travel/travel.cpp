#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[2]==s2[2]||(s1[1]==s2[1]&&s1[0]==s2[0])){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			cout<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}else{
		if(s2[2]=='F'||s2[2]=='D'){
			cout<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	if(s1[2]==s2[2]){
		int x=s1[0]-'0'+(s1[1]-'0')*10;
		int y=s2[0]-'0'+(s2[1]-'0')*10;
		if(abs(x-y)==1){
			cout<<1;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		int x=s1[2]-'A';
		int y=s2[2]-'A';
		if(abs(x-y)==1||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'&&s1[2]=='D'){
			cout<<1;
		}else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
