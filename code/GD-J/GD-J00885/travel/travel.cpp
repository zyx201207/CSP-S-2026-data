#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b.substr(0,2)==d.substr(0,2)){
			cout<<1;
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')){
				cout<<1;
				if(abs(b[2]-d[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
}
