#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,c,ap,cp,aw,cw,ac,cc;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	ap=(b[0]-'0')*10+(b[1]-'0');
	cp=(d[0]-'0')*10+(d[1]-'0');
	aw=b[2]-'A';
	cw=d[2]-'A';
	ac=aw/3;
	cc=cw/3;
	cout<<b<<" "<<d<<" "<<ap<<" "<<cp<<" "<<aw<<" "<<cw<<" "<<ac<<" "<<cc<<endl;
	cout<<(a==c);
	cout<<(a==c) && (ap==cp);
	cout<<(a==c) && (ap==cp) && (ac==cc);
	cout<<(a==c) && (ap==cp) && (ac==cc) && (abs(aw-cw)==1);
	return 0;
}
