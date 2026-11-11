#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f;
int main(){
  	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1,f=1;
	else cout<<0;
	if(f==1&&b[0]+b[1]==d[0]+d[1]) cout<<1;
	else cout<<0,f=0;
	if(f==1&&b[2]<='C'&&d[2]<='C') cout<<1;
	else if(f==1&&b[2]>='D'&&d[2]>='D') cout<<1;
	else cout<<0,f=0;
	if(f==1&&abs(b[2]-d[2])<=1) cout<<1;
	else cout<<0;
	return 0;
}
