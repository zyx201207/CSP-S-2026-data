#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>a>>b>>c>>d;
	if(a!=c) return cout<<"0000",0;
	string t1=b.substr(0,2),t2=d.substr(0,2);
	if(t1!=t2) return cout<<1000,0;
	if((b[2]<='C'&&d[2]>'C')||(b[2]>'C'&&d[2]<='C')) return cout<<1100,0;
	if(abs(b[2]-d[2])>1) return cout<<1110,0;
	cout<<1111;
	return 0;
}
