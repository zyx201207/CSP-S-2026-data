#include <bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[1]==d[1]&&b[0]==d[0]){
		cout<<1;
	}else{
		cout<<0;
	}
	int cnt=0;
	if(b[1]==d[1]&&b[0]==d[0]&&((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))){
		cout<<1;
		cnt=1;
	}else{
		cout<<0;
	}
	if(cnt==0){
		cout<<0;
	}else{
		if(b[2]=='A'&&d[2]=='C'){
			cout<<0;
		}else if(b[2]=='C'&&d[2]=='A'){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	return 0;
}