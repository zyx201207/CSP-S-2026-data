#include<bits/stdc++.h>
using namespace std;
string an,bn,am,bm;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>an>>bn>>am>>bm;
	bool vo=0,vt=0,vf=0;
	if(an==am) cout<<'1',vo=1;
	else cout<<'0';
	if(vo && bn[0]==bm[0] && bn[1]==bm[1]) cout<<'1',vt=1;
	else cout<<'0';
	char p=bn[2],q=bm[2];
	if(vt && ((p<='C' && q<='C') || (p>='D' && q>='D'))) cout<<'1',vf=1;
	else cout<<'0';
	if(p=='F') p='E';
	if(q=='F') q='E';
	if(vo && vt && vf && max(p-q,q-p)==1) cout<<'1';
	else cout<<'0';
}
