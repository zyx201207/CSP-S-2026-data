#include<bits/stdc++.h>
using namespace std;
const int M=1e5*1+10;

int main(){
	//ios::sync_with_stdio(NULL);
	//cin.tie(0);
	//cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]<='C'){
		if(d[2]<='C')
			cout<<1;
		else cout<<0;
	}
	if(b[2]>'C'){
		if(d[2]>'C')
			cout<<1;
		else cout<<0;
	}
	if(b[2]==char(int(d[2]+1))||b[2]==char(int(d[2]-1))){
		if(b[2]<='C'&&d[2]<='C')cout<<1;
		else if(b[2]>'C'&&d[2]>'C')cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
