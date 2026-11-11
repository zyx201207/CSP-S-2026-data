#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
	int x2=(c[0]-'0')*10+c[1]-'0';
	int x1=(a[0]-'0')*10+a[1]-'0';
	if(x1!=x2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}
	int p1=b[0]-'0'*10+b[1]-'0';
	int p2=d[0]-'0'*10+d[1]-'0';
	if(p1!=p2){
		cout<<"000";
		return 0;
	}
	else{
		cout<<1;
	}
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
		cout<<1;
	}
	else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	int z1=b[2]-'A';
	int z2=d[2]-'A';
	if(z1+1==z2||z2+1==z1){
		cout<<1;
	}
	else{
		cout<<0;
	}
} 
