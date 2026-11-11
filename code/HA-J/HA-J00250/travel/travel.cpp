#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool o=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a>>c>>b>>d;
	if(a!=b)o=0;
	cout<<o;
	if(!(c[0]==d[0]&&c[1]==d[1]))o=0;
	cout<<o;
	if(!((c[2]<='C'&&d[2]<='C')||(c[2]>='D'&&d[2]>='D')))o=0;
	cout<<o;
	if(abs(c[2]-d[2])!=1)o=0;
	cout<<o;
	return 0;
}
