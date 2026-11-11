#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char n,m;
	long long a,b,x,y;
	cin>>a>>x>>n>>b>>y>>m;
	if(a==b){
		cout<<1; 
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(x==y){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(n-'0'<='C'-'0'&&m-'0'<='C'-'0'){
		cout<<1;
		if(n-'0'=='A'-'0'||n-'0'=='B'-'0'){
			if(m-'0'=='A'-'0'||m-'0'=='B'-'0'){
				cout<<1;
				return 0;
	     	}
		}	
	}else{
		if(n-'0'=='D'-'0'||n-'0'=='F'-'0'){
			if(m-'0'=='D'-'0'||m-'0'=='F'-'0'){
				cout<<1<<1;
				return 0;
	     	}
		}
		cout<<0<<0;
	    return 0;
	}
	if(n-'0'=='B'-'0'||n-'0'=='C'-'0'){
		if(m-'0'=='B'-'0'||m-'0'=='C'-'0'){
			cout<<1;
	    }else{
	     	cout<<0;
	     	return 0;
		}
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}
