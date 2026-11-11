#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int a1,a2,d1,d2;
bool b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	cout<<(c1==c3);
	a1=c2[0]*10+c2[1];
	a2=c4[0]*10+c4[1];
	d1=int(c2[2])-64;
	d2=int(c4[2])-64;
	b1=(d1<=3);
	b2=(d2<=3);
	if(c1==c3)cout<<(a1==a2);
	else cout<<0;
	if(c1==c3&&a1==a2)cout<<(b1==b2);
	else cout<<0;
	if(c1==c3&&a1==a2&&b1==b2)cout<<(abs(d1-d2)==1);
	else cout<<0;
	return 0;
}
