#include<bits/stdc++.h>
using namespace std;

int a,c;
string b,d;
bool x;

bool check1(){
	if(a!=c) return false;
	if(b[0]!=d[0]||b[1]!=d[1]) 
		return false;
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')
			return true;
	else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')
			return true;
	else return false;
}

bool check2(){
	if(x==false) return false;
	if(b[2]>='A'&&b[2]<='C'){
		if(b[2]+1==d[2]||b[2]-1==d[2])
			return true;
		else return false;
	}
	
	if(b[2]>='D'&&b[2]<='F'){
		if(b[2]=='D'&&d[2]=='F') return true;
		else if(b[2]=='F'&&d[2]=='D') return true;
		else return false;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	
	if(a==c) cout<<1;
	else cout<<0;
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1])
		cout<<1;
	else cout<<0;
	
	if(check1()){
		cout<<1;
		x=true;
	}
	else cout<<0;
	
	if(check2()) cout<<1;
	else cout<<0;
	
	return 0;
} 
