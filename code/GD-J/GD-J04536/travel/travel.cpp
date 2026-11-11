#include <bits/stdc++.h>
using namespace std;
int p,w,l;
bool c=0;
string n,m,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>x>>y;
	if(n==x)cout<<1;                   else {	cout<<"0000";	return 0;	}
	if(m[0]+m[1]==y[0]+y[1])cout<<1;   else {	cout<<"000";	return 0;	}
	if(m[2]<='C'&&y[2]<='C' || m[2]>'C'&&y[2]>'C')cout<<1;
	                                   else {	cout<<"00";	return 0;	}
	if(int(m[1]+1==y[1]||m[1]-1==y[1]))cout<<1;
	else cout<<0;
	return 0;
}
