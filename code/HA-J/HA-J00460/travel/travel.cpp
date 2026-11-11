#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	int l2=(b1[0]-48)*10+(b1[1]-48);
	int l1=(a1[0]-48)*10+(a1[1]-48);
	int h1=(a1[2]-65);
	int h2=(b1[2]-65);
	if(a==b) cout<<'1';
	else cout<<'0';
	if(a==b && l2==l1) cout<<'1';
	else cout<<'0';
	if(a==b && l2==l1 && ((h1>2&&h2>2)||(h1<3&&h2<3))) cout<<'1';
	else cout<<'0';
	if(a==b &&((l1==l2-1 && h1==h2) || (l1==l2+1 && h1==h2) || (l1==l2 && h1==h2-1) || (l1==l2 && h1==h2+1)) && ((h1>2&&h2>2)||(h1<3&&h2<3))) cout<<'1';
	else cout<<'0';
	return 0;
}
