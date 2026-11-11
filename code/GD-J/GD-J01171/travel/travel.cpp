#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,c,c1;
string a,b,a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a1>>b1;n=1;
	c=(b[0]-'0')*10+(b[1]-'0');c1=(b1[0]-'0')*10+(b1[1]-'0');
	n*=(a==a1);cout<<n;
	n*=(c==c1);cout<<n;
	n*=((b[2]<='C')==(b1[2]<='C'));cout<<n;
	if(b[2]<='C')n*=(abs(b[2]-b1[2])==1);
	cout<<n;
	return 0;
}
