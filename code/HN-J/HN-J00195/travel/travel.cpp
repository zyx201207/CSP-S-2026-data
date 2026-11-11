#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0] and b[1]==d[1]){
		cout<<1;
	if(b[2]=='A'){
		if(d[2]=='B' or d[2]=='C'){
			cout<<1;
			if(d[2]=='B')cout<<1;
			else cout<<0;
		}
		else return cout<<"00",0;
	}
	if(b[2]=='B'){
		if(d[2]=='A' or d[2]=='C')return cout<<11,0;
		else return cout<<"00",0;
	}
	if(b[2]=='C'){
		if(d[2]=='A' or d[2]=='B'){
			cout<<1;
			if(d[2]=='B')return cout<<1,0;
			else cout<<0;
		}
		else return cout<<"00",0;
	}
	if(b[2]=='D'){
		if(d[2]=='F')return cout<<11,0;
		else return cout<<"00",0;
	}
	if(b[2]=='F'){
		if(d[2]=='D')return cout<<11,0;
		else return cout<<"00",0;
	}
	}
	else{
		return cout<<"000",0;
	}
	return 0;
} 
