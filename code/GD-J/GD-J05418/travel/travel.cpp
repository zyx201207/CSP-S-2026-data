#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d;
ll q,w,e,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
//	cout<<c<<a<<d<<b;
	if(a==c) q=1;
	if((b[0]==d[0]&&d[1]==b[1])&&q==1) w=1;
	if(((b[2]>'C'&&d[2]>'C')||(b[2]<'D'&&d[2]<'D'))&&q==1&&w==1) e=1;
	if((b[2]==d[2]-1||d[2]==b[2]-1)&&q==1&&w==1&&e==1) r=1;
	cout<<q<<w<<e<<r;
	
	return 0;
}
