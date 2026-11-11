#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if(b[2]>='D'&&d[2]>='D'){
				cout<<"1111";
			}else if(b[2]<='C'&&d[2]<='C'){
				if(b[2]=='A'&&d[2]=='C') cout<<"1110";
				else if(b[2]=='C'&&d[2]=='A') cout<<"1110";
				else cout<<"1111";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
}
