#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1<<'\n';
		if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1<<'\n';
		if((b[2]>'C'&&d[2]<='C')||(d[2]>'C'&&b[2]<='C')){
		cout<<0<<'\n';
		cout<<0<<'\n';
	} 
		else if(b[2]>'C'&&d[2]>'C'){
		cout<<1<<'\n';
		cout<<1<<'\n';
	}
	else if(b[2]<='C'&&d[2]<='C'){
		cout<<1<<'\n';
		if(abs(b[2]-d[2])==1){
			cout<<1<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
	}else{
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
	}
	}else{
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
	}
	return 0;
}
