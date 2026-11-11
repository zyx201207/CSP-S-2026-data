#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
string s,t,r,n,q,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>t>>r>>n;
	if (s==r){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if (t[0]==n[0] and t[1]==n[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if (t[2]=='A'){
		if (n[2]=='B'){
			cout<<11;
			return 0;
		}else if (n[2]=='C'){
			cout<<10;
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}else if (t[2]=='B'){
		if (n[2]=='A'){
			cout<<11;
			return 0;
		}else if (n[2]=='C'){
			cout<<11;
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}else if (t[2]=='C'){
		if (n[2]=='A'){
			cout<<10;
			return 0;
		}else if (n[2]=='B'){
			cout<<11;
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}else if (t[2]=='D'){
		if (n[2]=='F'){
			cout<<11;
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}else if (t[2]=='F'){
		if (n[2]=='D'){
			cout<<11;
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}
	
	return 0;
}
