#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll h,h2;
	char a,b,c,a2,b2,c2;
	cin>>h>>a>>b>>c;
	cin>>h2>>a2>>b2>>c2;
	ll n=(a-'0'*10)+(b-'0');
	ll n2=(a2-'0'*10)+(b2-'0');
	if(h==h2)cout<<1;
	else cout<<0;
	if(h==h2 and  n==n2) cout<<1;
	else cout<<0;
	if(h==h2 and  n==n2 and (c<'D' and c2<'D' or c>'C' and c2>'C')){
		cout<<1;
	}
	else cout<<0;
	if(h==h2 and  n==n2 and (c<'D' and c2<'D' or c>'C' and c2>'C') and abs(int(c-c2))==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
