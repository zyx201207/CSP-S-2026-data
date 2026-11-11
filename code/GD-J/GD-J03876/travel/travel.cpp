#include<bits/stdc++.h>
using namespace std;
long long a,b;
string c,d;
int main(){
	cin>>a>>c>>b>>d;
	if(a==b){cout<<"1";}
	a=int(c[0]-48)*10+int(c[1]-48);
	b=int(d[0]-48)*10+int(d[1]-48);
	if(a==b){cout<<"1";}
	if(c[2]<='C'&&d[2]<='C'||c[2]>'C'&&d[2]>'C'&&c[2]<='F'&&d[2]<='F'){cout<<"1";}
	if(c[2]<='A'&&d[2]<='B'||c[2]<='B'&&d[2]<='A'||c[2]<='B'&&d[2]<='C'||c[2]<='C'&&d[2]<='B'||c[2]<='D'&&d[2]<='F'||c[2]<='F'&&d[2]<='D'){cout<<"1";}
	return 0;
}
