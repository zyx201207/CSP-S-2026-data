#include<bits/stdc++.h>
using namespace std;
string a,b,aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>aa>>bb;
	if(a[0]==aa[0] && a[1]==aa[1]) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==bb[0] && b[1]==bb[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A' || b[2]=='B' || b[2]=='C'){
		if(bb[2]=='A' || bb[2]=='B' || bb[2]=='C') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}else if(b[2]=='D' || b[2]=='F'){
		if(bb[2]=='D' || bb[2]=='F') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if(b[2]=='A'){
		if(bb[2]=='B') cout<<1;
		else cout<<0;
	}
	if(b[2]=='B'){
		if(bb[2]=='A' || bb[2]=='C') cout<<1;
		else cout<<0;
	}
	if(b[2]=='C'){
		if(bb[2]=='B') cout<<1;
		else cout<<0;
	}
	if(b[2]=='D'){
		if(bb[2]=='F') cout<<1;
		else cout<<0;
	}
	if(b[2]=='F'){
		if(bb[2]=='D') cout<<1;
		else cout<<0;
	}
	return 0;
}
