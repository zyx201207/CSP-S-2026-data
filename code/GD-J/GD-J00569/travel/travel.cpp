#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char a,b;
	cin>>a1>>a2>>a>>b1>>b2>>b;
	if(a1==b1)cout<<1;
	else cout<<0;
	if(a1==b1&&a2==b2)cout<<1;
	else cout<<0;
	if(a1==b1&&a2==b2&&((a<='C'&&b<='C')||(a>='D'&&b>='D')))cout<<1;
	else cout<<0;
	if(a1==b1&&a2==b2&&(a==b+1||b==a+1)&&!(a=='C'&&b=='D')&&!(a=='D'&&b=='C'))cout<<1;
	else if(a1==b1&&a2==b2&&(a=='D'&&b=='F'||a=='F'&&b=='D'))cout<<1;
	else cout<<0;
} 
