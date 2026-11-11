#include<bits/stdc++.h> 
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c>>a>>d>>b;
	if(c[1]-'0'!=d[1]-'0'||c[0]-'0'!=d[0]-'0'){
		cout<<"0000";
		return 0;
	}
	else{	
	cout<<1;
	}
	if(a[0]-'0'==b[0]-'0'&&a[1]-'0'==b[1]-'0')cout<<1;
	else {
	cout<<"000";	
	return 0;
	}
	if(a[2]-'A'==0||a[2]-'A'==1||a[2]-'A'==2){
		if(b[2]-'A'==0||b[2]-'A'==1||b[2]-'A'==2){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(b[2]-'A'==3||b[2]-'A'==4){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(int(a[2]-'A')+1==int(b[2]-'A')||int(a[2]-'A')-1==int(b[2]-'A')){
	cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
