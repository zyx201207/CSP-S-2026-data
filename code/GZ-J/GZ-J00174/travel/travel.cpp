//GZ-J00174 ºúî£³¿
#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
long long r,x,cr,cx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if (c1==c3) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	r=c2[0]*10+c2[1],x=c4[0]*10+c4[1];
	if (r==x) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if ((c2[2]<='C' && c4[2]<='C') || (c2[2]>'C' && c4[2]>'C'))
		cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if (c2[2]-'A'+1==c4[2]-'A' || c2[2]-'A'-1==c4[2]-'A') cout<<1;
	else cout<<0;
	return 0;
}
