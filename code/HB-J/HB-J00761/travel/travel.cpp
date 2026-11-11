#include<bits/stdc++.h>
using namespace std;
int c1,c2,zz1,zz2,b1,b2;
char z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>c1>>zz1>>z1>>c2>>zz2>>z2;
	int cz=int(z1-z2);
	if(z1=='A'||z1=='B'||z1=='C') b1=1;
	else b1=2;
	if(z2=='A'||z2=='B'||z2=='C') b2=1;
	else b2=2;
	if(c1==c2){cout<<1;}
	else{cout<<0;}
	if(c1==c2&&zz1==zz2){cout<<1;}
	else cout<<0;
	if(c1==c2&&zz1==zz2&&b1==b2) cout<<1;
	else cout<<0;
	if(c1==c2&&zz1==zz2&&b1==b2&&abs(cz)==1) cout<<1;
	else cout<<0;
	return 0;
}
