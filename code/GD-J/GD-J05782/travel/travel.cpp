#include<bits/stdc++.h>
using namespace std;
string a,b,A,B;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>A>>B;
	if(a!=A){
		cout<<"0000";
	}else{
		cout<<"1";
		if(b[0]!=B[0]||b[1]!=B[1]) cout<<"000";
		else{
			cout<<"1";
			if(b[2]>'C'&&B[2]<='C') cout<<"00";
			else{
				if(b[2]<='C'&&B[2]>'C'){
					cout<<"00";
					return 0;
				}
				cout<<"1";
				if(b[2]+1==B[2]||b[2]-1==B[2]) cout<<"1";
				else cout<<"0";
			}
		}
	}
	
	
	return 0;
}
