#include<bits/stdc++.h>
using namespace std;
string s1,s2,r1,r2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>r1>>r2;
	if(s1!=r1){
		cout<<"0000";
	}else{
	cout<<"1";
	if(s2[0]!=r2[0]||s2[1]!=r2[1]) {
		cout<<"000";
	}else{
	cout<<"1";
	char a=s2[2],b=r2[2];
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C'){
			cout<<"1";
			if(a-b==1||b-a==1) cout<<"1";
			else cout<<0; 
		}
		else cout<<"00";
	}
	else{
		if(b=='D'||b=='F'){
			cout<<"11";
		}
		else cout<<"00";
	}
}
}
	return 0;
}

