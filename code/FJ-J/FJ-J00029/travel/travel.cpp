#include<bits/stdc++.h>
using namespace std;
string a,b,c,d; char x,y;
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else return cout<<"0000",0;
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else return cout<<"000",0;
	x=b[2],y=d[2];
	if(('A'<=x&&x<='C'&&'A'<=y&&y<='C')||('D'<=x&&x<='E'&&'D'<=y&&y<='E')) cout<<1;
	else return cout<<"00",0;
	if(abs(x-y)==1) cout<<1;
	else cout<<0; 
	return 0;
}
// rp++;
