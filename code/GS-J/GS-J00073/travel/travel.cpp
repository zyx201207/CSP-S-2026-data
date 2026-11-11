#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	int a=0,b=0,c=0,d=0;
	string e,f,g,h;
	cin>>e>>f>>g>>h;
	if(e==g)a=1;
	if(a==1&&f[0]==h[0]&&f[1]==h[1])b=1;
	if(b==1){
		if(f[2]<'D'&&h[2]<'D')c=1;
		if(f[2]>'C'&&h[2]>'C')c=1;
	}
	if(a==1&&b==1&&c==1){
		if(f[2]-1==h[2]||f[2]+1==h[2])d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
