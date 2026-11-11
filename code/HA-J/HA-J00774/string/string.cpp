#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,l,r) for(ll i=l;i<=r;i++)
#define rfr(i,l,r) for(ll i=l;i>=r;i--)
#define lwq return

ll n,a[200050],ans;
char c[200050];
string s=" ";

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	fr(i,1,n){
		cin>>a[i]>>c[i];
		fr(j,1,a[i])	s+=c[i];
	}
	ll L=s.size()-1;
	fr(i,1,L/2) if(s[i]!=s[L-i+1]) ans++;
	cout<<ans;
	lwq 0;
}