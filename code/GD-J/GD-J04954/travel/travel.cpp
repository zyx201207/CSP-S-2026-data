#include<bits/stdc++.h>
using namespace std;
string n,m,s,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>s>>c;
	if(n==s)cout<<1;
	else{
		cout<<"0000";
		return 0;
	} 
	if((m[0]==c[0])&&(m[1]==c[1]))cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((m[2]<='C')&&(c[2]<='C')&&(m[2]!=c[2]))cout<<1;
	else if((m[2]>='D')&&(c[2]>='D')&&(m[2]!=c[2]))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((m[2]-1==c[2])||(m[2]+1==c[2]))cout<<1;
	else cout<<'0';
	return 0;
} 
