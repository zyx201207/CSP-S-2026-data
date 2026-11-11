#include <iostream>
#include <cstdio>

using namespace std;

int cx1,p1,cx2,p2;
char zw1,zw2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>cx1>>p1>>zw1>>cx2>>p2>>zw2;
	
	if(cx1==cx2) cout<<1;
	else cout<<0;
	
	if(cx1==cx2&&p1==p2) cout<<1;
	else cout<<0;
	
	if(cx1==cx2&&p1==p2&&((zw1<='C'&&zw2<='C')||(zw1>='D'&&zw2>='D'))) cout<<1;
	else cout<<0; 
	
	if(cx1==cx2&&p1==p2&&((zw1<='C'&&zw2<='C')||(zw1>='D'&&zw2>='D'))&&((zw1>='D'&&zw2>='D')||((zw1<='C'&&zw2<='C')&&(zw1=='B'||zw2=='B')))) cout<<1;
	else cout<<0;
	return 0;
} 
