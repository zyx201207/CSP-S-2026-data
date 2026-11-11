#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cv,sv;
	cin >> c >> s >> cv >> sv;
	a=(s[0]-'0')*10+(s[1]-'0');
	b=(sv[0]-'0')*10+(sv[1]-'0');
	if(c==cv){
		cout<<1;
		if(a==b){
			cout<<1;
			if((s[2]<='C'&&sv[2]<='C')||(s[2]>'C'&&sv[2]>'C')){
				cout<<1;
				if(abs(s[2]-sv[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
