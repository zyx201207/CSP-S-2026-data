#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int a1=a[0]-'0'+a[1]-'0';
	int b1=b[0]-'0'+b[1]-'0';
	int c1=c[0]-'0'+c[1]-'0';
	int d1=d[0]-'0'+d[1]-'0';
	if(a1==c1)cout<<'1';
	else{
		cout<<"0000";
		return 0;
	} 
	if(b1==d1)cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]<='C'&&d[2]<='C'){
		cout<<'1';
	}else if(b[2]>='D'&&d[2]>='D'){
		cout<<'1';	
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(d[2]-b[2])==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}

