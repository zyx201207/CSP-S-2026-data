#include<bits/stdc++.h>
using namespace std;
char a[2],b[3],c[2],d[3],e='0',f='0',g='0',h='0';
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(!(a[0]==c[0]&&a[1]==c[1]))cout<<'0'<<'0'<<'0'<<'0';
	else if(!(b[0]==d[0]&&b[1]==d[1]))cout<<'1'<<'0'<<'0'<<'0';
	else if(!((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')))cout<<'1'<<'1'<<'0'<<'0';
	else if(!(b[2]==d[2]-1||b[2]==d[2]+1))cout<<'1'<<'1'<<'1'<<'0';
	else cout<<'1'<<'1'<<'1'<<'1';
	return 0;
}
