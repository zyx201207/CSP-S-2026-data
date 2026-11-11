#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,sub1,sub2;
	cin>>s1>>s2>>sub1>>sub2;
	if(s1==sub1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s2.substr(0,2)==sub2.substr(0,2)) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(s2[2]=='B'){
		if(sub2[2]=='A'||sub2[2]=='C') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s2[2]=='C'){
		if(sub2[2]=='B'||sub2[2]=='A') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s2[2]=='D'){
		if(sub2[2]=='F') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s2[2]=='A'){
		if(sub2[2]=='B'||sub2[2]=='C') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s2[2]=='F'){
		if(sub2[2]=='D') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if(s2[2]=='B'){
		if(sub2[2]=='A'||sub2[2]=='C') cout<<1;
		else{
			cout<<"0";
			return 0;
		}
	}
	else if(s2[2]=='C'){
		if(sub2[2]=='B') cout<<1;
		else{
			cout<<"0";
			return 0;
		}
	}
	else if(s2[2]=='D'){
		if(sub2[2]=='F') cout<<1;
		else{
			cout<<"0";
			return 0;
		}
	}
	else if(s2[2]=='A'){
		if(sub2[2]=='B') cout<<1;
		else{
			cout<<"0";
			return 0;
		}
	}
	else if(s2[2]=='F'){
		if(sub2[2]=='D') cout<<1;
		else{
			cout<<"0";
			return 0;
		}
	}
	return 0;
} 
