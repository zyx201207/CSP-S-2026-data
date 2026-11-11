#include<bits/stdc++.h>
using namespace std;
string n,m,i,j;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>i>>j;
	if(n==i)cout<<1;
	else cout<<0;
	if(n==i&&m[0]==j[0]&&m[1]==j[1])cout<<1;
	else cout<<0;
	if(n==i&&m[0]==j[0]&&m[1]==j[1]&&m[2]+j[2]=='F'+'D')cout<<1;
	else if(n==i&&m[0]==j[0]&&m[1]==j[1]&&m[2]!='D'&&m[2]!='F'&&j[2]!='D'&&j[2]!='F')cout<<1;
	else cout<<0;
	if(n==i&&m[0]==j[0]&&m[1]==j[1]&&max(m[2]-j[2],j[2]-m[2])==1&&m[2]+j[2]!='C'+'D')cout<<1;
	else cout<<0;
	return 0;
}
