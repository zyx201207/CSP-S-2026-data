//GZ-J00490 遵义市第十二中学 黄正垚
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";	
	}else{
		cout<<"0";
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	int a1=b[2]-55;
	int b1=d[2]-55;
	if(a1<='C'-55&&b1<='C'-55||b1>'C'-55&&a1>'C'-55){
		cout<<"1";
		
	}else{
		cout<<"0";
	}
	if(a1<='C'-55&&b1<='C'-55||b1>'C'-55&&a1>'C'-55){
		if(a1-1==b1||b1-1==a1){
			cout<<"1";
		}else{
			cout<<"0";
		} 
	}
	else{
		cout<<"0";
	}
	
	return 0;
}
 
