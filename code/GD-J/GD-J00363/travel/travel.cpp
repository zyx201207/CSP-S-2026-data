#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,c;
string b,d;
int pd(char x){
	if(x=='A'||x=='B'||x=='C') return 1;
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}else{
		cout<<'1';
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<'1';
			if(pd(b[2])==pd(d[2])){
				cout<<'1';
				if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')) cout<<'0';
				else cout<<1;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	return 0;
}
