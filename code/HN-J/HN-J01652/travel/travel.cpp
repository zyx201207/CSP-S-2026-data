#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	int x=(b[0]-'0')*10+b[1]-'0';
	int y=(d[0]-'0')*10+d[1]-'0';
	bool f=0;
	if(x==y){
		cout<<1;
		f=1;
	}
	else {
		cout<<"000";
		return 0;
	}
	if(b[2]<='C' && d[2]<='C' || b[2]>='D' && d[2]>='D')cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	char n=b[2],m=d[2];
	if(f && n+1==m || m+1==n){
		if(m=='C' && n=='D' || n=='C' && m=='D'){
			cout<<0;
			return 0;
		}
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
