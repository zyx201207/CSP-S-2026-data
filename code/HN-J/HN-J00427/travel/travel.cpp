#include<bits/stdc++.h>
using namespace std;
string cx1,cx2,zw1,zw2;
int bh(string x){
	return (x[0]-'0')*10+x[1]-'0';
}
bool p(string x,string y){
	return ((x[2]>='D'&&y[2]>='D')||(x[2]<='C'&&y[2]<='C'));
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	cout<<(cx1==cx2);
	cout<<((cx1==cx2)&&bh(zw1)==bh(zw2));
	cout<<(((cx1==cx2)&&bh(zw1)==bh(zw2))&&p(zw1,zw2));
	cout<<((((cx1==cx2)&&bh(zw1)==bh(zw2))&&p(zw1,zw2))&&abs(zw1[2]-zw2[2])==1);
 } 

