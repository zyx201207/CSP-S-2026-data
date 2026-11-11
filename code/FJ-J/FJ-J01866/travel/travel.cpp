#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool flag = true;
	if(a==c && flag){
		cout<<1;
	}else{
		cout<<0;
		flag = false;
	}
	if(b[0]==d[0] && b[1]==d[1] && flag){
		cout<<1;
	}else{
		cout<<0;
		flag = false;
	}
	if(!(b[2]=='C' && d[2]=='D') && !(b[2]=='D' && d[2]=='C') && flag){
		cout<<1;
	}else{
		cout<<0;
		flag = false;
	}
	if((b[2]-d[2]==1 || b[2]-d[2]==-1) && flag){
		cout<<1;
	}else{
		cout<<0;
		flag = false;
	}
	return 0;
} 
