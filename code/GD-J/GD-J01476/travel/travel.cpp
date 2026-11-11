#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a1>>b1;
	if(a==a1)cout<<1;
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(b1[0]==b[0]&&b1[1]==b[1]){
		cout<<1;
	}
	else{
		cout<<"000"<<endl;
		return 0;
	}
	if((b[2]<='C'&&b1[2]<='C')||(b[2]>'C'&&b1[2]>'C'))cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if(b[2]+1==b1[2]||b1[2]+1==b[2])cout<<1;
	else cout<<0;
	
}
