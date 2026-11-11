#include<bits/stdc++.h>
using namespace std;
int a,c,g=1;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else {
		g=0;
		cout<<0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&g)cout<<1;
	else {
		g=0;
		cout<<0;
	}
	if(((b[2]<'D'&&d[2]<'D')||(b[2]>='D'&&d[2]>='D'))&&g)cout<<1;
	else {
		g=0;
		cout<<0;
	}
	if((b[2]+1==d[2]||d[2]+1==b[2])&&g)cout<<1;
	else cout<<0;
}
