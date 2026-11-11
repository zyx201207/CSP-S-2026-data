#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k,h;
char c,v;
ll f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>c>>k>>h>>v;
	if(n==k) cout<<1,f1=1;
	else cout<<0,f1=0;
	if(f1&&m==h) cout<<1,f2=1;
	else cout<<0,f2=0;
	ll cc=(ll)(c-'A'+1);
	ll vv=(ll)(v-'A'+1);
	if(f2&&cc<=3&&vv<=3||f2&&cc>=4&&vv>=4) cout<<1,f3=1;
	else cout<<0,f3=0;
	if(f3&&abs(cc-vv)==1) cout<<1;
	else cout<<0;
	return 0;
}

