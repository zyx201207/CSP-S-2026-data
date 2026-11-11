#include<bits/stdc++.h>
using namespace std;
string x,y;
string a,b;
bool c=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x==y)cout<<1;
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(a[0]==b[0] && a[1]==b[1])cout<<1;
	else cout<<0;
	if(((a[2]>='D'&&b[2]>='D') || (a[2]<='C'&&b[2]<='C')) && (a[0]==b[0] && a[1]==b[1]))cout<<1;
	else cout<<0;
	if(a[2]>='D'&&b[2]>='D')cout<<1;
	else if(((abs(a[2]-b[2])==1) && (a[2]!='C' || b[2]!='D')) && ((a[2]>='D'&&b[2]>='D') || (a[2]<='C'&&b[2]<='C')) && (a[0]==b[0] && a[1]==b[1]))cout<<1;
		 else cout<<0;
	return 0;
}
