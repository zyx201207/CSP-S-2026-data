#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c) f=0;
	cout<<f;
	if(b[0]!=d[0]||b[1]!=d[1]) f=0;
	cout<<f;
	if(b[2]>='D'&&d[2]<'D') f=0;
	if(b[2]<'D'&&d[2]>='D') f=0;
	cout<<f;
	int x=b[2]-d[2];
	if(abs(x)!=1) f=0;
	cout<<f;
	return 0;
}
