#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int mn=4e6+6;
string s;
ll n,ans;
ll l,r;
struct node{
	ll d;
	char c;
}q[mn];
int main ( ) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>q[i].d>>q[i].c;
	r=1;l=n;
	while(l>r){
		ll bc=min(q[r].d,q[l].d);
		q[r].d-=bc;
		q[l].d-=bc;
		if(q[r].c!=q[l].c) ans+=bc;
		if(!q[r].d) r++;
		if(!q[l].d) l--;
	}
	cout<<ans;
	return 0;
} 
