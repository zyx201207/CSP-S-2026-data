#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int bb,dd;
	bb=10*(b[0]-'0')+(b[1]-'0');
	dd=10*(d[0]-'0')+(d[1]-'0');
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(bb==dd){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]<='C' && b[2]>='A' && d[2]<='C' && d[2]>='A'){
		cout<<1;
	}
	else if(b[2]<='F' && b[2]>='D' && d[2]<='F' && d[2]>='D' && b[2]!='E' && d[2]!='E'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1){
		cout<<1;
	}
	else{
		cout<<"0";
	}
	return 0;
} 
