#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string b,d;
int a,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<0<<0<<0<<0;
		return 0;
	} 
	cout<<1;
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
		cout<<1;
		if(int(b[2])+1==d[2]||int(b[2])-1==d[2]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
		cout<<1<<1;
		return 0;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	
	
	return 0;
} 
