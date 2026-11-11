#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,l,r) for(ll i=l;i<=r;i++)
#define rfr(i,l,r) for(ll i=l;i>=r;i--)
#define lwq return

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a,b;string c,d;
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000";
		lwq 0;
	}
	cout<<1;
	if(c[0]!=d[0]||c[1]!=d[1]){
		cout<<"000";
		lwq 0;
	}
	cout<<1;
	if(((c[2]-'A'+1<=3)&&(d[2]-'A'+1<=3))||((c[2]-'A'+1>=4)&&(c[2]-'A'+1>=4)))	cout<<1;
	else {
		cout<<"00";
		lwq 0;
	}
	if((abs(c[2]-d[2])==1)||((abs(c[2]-d[2])==2)&&(c[2]=='D'||c[2]=='F')))	cout<<1;
	else cout<<0;
	lwq 0;
}