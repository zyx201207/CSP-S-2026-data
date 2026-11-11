#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel1.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
	cout<<1;
	if(b[0]==d[0]&&b[1]==d[1]){
	cout<<1;
	if((b[3]<='C'&&d[3]<='C')||(b[3]>'C'&&d[3]>'C')){
	cout<<1;
	if(b[3]==d[3]+1||b[3]==d[3]-1){
		cout<<1;
	}else{
		cout<<0;
	}
}
	else{
	cout<<"00";
}
    }else{
	cout<<"00";
}
	}else{
	cout<<"0000";
}
} 
