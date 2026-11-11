#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string as,at,bs,bt;
bool f=1,m=1,n=1;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>as>>at>>bs>>bt;
	if(as==bs){
		cout<<1;
	}else{
		cout<<0;
		f=0;
	}
	if(f&&at[0]==bt[0]&&at[1]==bt[1]){
		cout<<1;
	}else{
		cout<<0;
		m=0;
	}
	if(m&&(((at[2]=='A'||at[2]=='B'||at[2]=='C')&&(bt[2]=='A'||bt[2]=='B'||bt[2]=='C'))||((at[2]=='D'||at[2]=='F')&&((bt[2]=='D'||bt[2]=='F'))))){
		cout<<1;
	}else{
		cout<<0;
		n=0;
	}
	if(n){
		if(at[2]=='A'&&bt[2]=='B'){
			cout<<1;
			return 0;
		}else if(at[2]=='B'&&bt[2]=='A'||at[2]=='B'&&bt[2]=='C'){
			cout<<1;
			return 0;
		}else if(at[2]=='C'&&bt[2]=='B'){
			cout<<1;
			return 0;
		}else if(at[2]=='D'&&bt[2]=='F'){
			cout<<1;
			return 0;
		}else if(at[2]=='F'&&bt[2]=='D'){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
