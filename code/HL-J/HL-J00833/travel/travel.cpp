#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel2.in","r",stdin);
	freopen("travel2.out","w",stdout);
	string a,b,c,d;cin>>a>>b>>c>>d;
	if(a[1]!=c[1]&&a[0]!=c[0]){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]-d[2]<=3||d[2]-b[2]<=3){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(d[2]-b[2]==1){
		cout<<1;
		return 0;
	}
	if(b[2]-d[2]==1){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}