#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,a,b;
	cin>>n>>m>>a>>b;
	if(n==a){
		cout<<1;
		if(m[0]==b[0]&&m[1]==b[1]){
			cout<<1;
			if((m[2]<='C'&&b[2]<='C')||(m[2]>'C'&&b[2]>'C')){
				cout<<1;
				if(abs(int(m[2]-b[2]))==1){
					cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else {
			cout<<"000";
			return 0;
		}
	}
	else cout<<"0000";
	return 0;
}
