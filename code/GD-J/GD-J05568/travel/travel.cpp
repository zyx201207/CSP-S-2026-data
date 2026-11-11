#include<bits/stdc++.h>
using namespace std;
int n,m,z=1;
string a,q,w,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>q>>w>>e;
	n=(a[0]-'0')*10+(a[1]-'0');
	m=(w[0]-'0')*10+(w[1]-'0');
	if(n==m) cout<<"1";
	else{cout<<"0000";return 0;}
	n=(q[0]-'0')*10+(q[1]-'0');
	m=(e[0]-'0')*10+(e[1]-'0');
	if(n==m) cout<<"1";
	else{cout<<"000";return 0;}
	char x=q[2],v=e[2];
	if((x<='C'&&v<='C')||(x>'C'&&v>'C')) cout<<"1";
	else{cout<<"00";return 0;}
	if((x-'0')==(v-'0')-1||int(x-'0')==(v-'0')+1) cout<<"1";
	else cout<<"0";
	return 0;
} 
