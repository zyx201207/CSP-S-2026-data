#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s>>m>>t;
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(s[0]!=t[0]||s[1]!=t[1]){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	if(s[2]=='A'){
		if(t[2]=='B'){
			cout<<"11";
			return 0;
		}
		else if(t[2]=='C'){
			cout<<"10";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s[2]=='B'){
		if(t[2]=='A'){
			cout<<"11";
			return 0;
		}
		else if(t[2]=='C'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s[2]=='C'){
		if(t[2]=='B'){
			cout<<"11";
			return 0;
		}
		else if(t[2]=='A'){
			cout<<"10";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s[2]=='D'){
		if(t[2]=='F'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(t[2]=='D'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
}
