#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<(a==c)<<((a==c)&&(b[0]==d[0])&&(b[1]==d[1]))<<(((a==c)&&(b[0]==d[0])&&(b[1]==d[1]))&&((b[2]>'C'&&d[2]>'C')||(b[2]<='C'&&d[2]<='C')))<<((((a==c)&&(b[0]==d[0])&&(b[1]==d[1]))&&((b[2]>'C'&&d[2]>'C')||(b[2]<='C'&&d[2]<='C')))&&((abs(b[2]-d[2])==1)||(b[2]+d[2]=='D'+'F')));	
}/*
. .
 . Oct31=Dec25
 .
. .Trick||Treat!=MerryCristmas! 
*/
