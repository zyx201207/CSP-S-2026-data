#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		e=1;
	    cout<<1;
    }else cout<<0;
    if(b[0]==d[0]&&b[1]==d[1]&&e==1){
    	cout<<1;
    	f=1;
	}else cout<<0;
	if(e==1&&f==1){
	if(b[2]<='C'&& d[2]<='C'||b[2]>='D'&&d[2]>='D'){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(b[2]>='D'&&d[2]>='D'){
		cout<<1;
		return 0;
	}
	if(d[2]=='A'&&b[2]=='B'||d[2]=='B'&&b[2]=='A'||d[2]=='B'&&b[2]=='C'||d[2]=='C'&&b[2]=='B'){
		cout<<1;
	}else cout<<0;
}else{
	cout<<0;
	cout<<0;
	return 0;
}
	return 0;
}
