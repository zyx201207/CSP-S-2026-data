#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		if(d[0]==b[0]&&d[1]==b[1]){
			if((d[2]<='C'&&b[2]<='C')||(d[2]>'C'&&b[2]>'C')){
				if(d[2]-1==b[2]||b[2]-1==d[2]){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
