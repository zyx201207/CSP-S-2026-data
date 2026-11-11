//GZ-J00163  遵义市汇川区第二小学 韩铭钊 
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int f=1;
    if(a!=c){
    	f=0;
    	cout<<0;
	}else{
		cout<<1;
	}
	if(f && b[0]==d[0] && b[1]==d[1]){
		cout<<1;
	}else{
		f=0;
		cout<<0;
	}
	if(f && (b[2]<='C' && d[2]<='C' || b[2]>'C' && d[2]>'C')){
		cout<<1;
	}else{
		f=0;
		cout<<0;
	}
	if(f && abs(b[2]-d[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

