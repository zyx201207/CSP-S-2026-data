#include <bits/stdc++.h>
using namespace std;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
ll n,m,h[500005],d[500005]{0},sd[500005]{0};
int main(void){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	F;
	ll i,j,s,mx=0;
	cin>>n>>m;
	for(i=1;i<=n;++i)cin>>h[i];
	sort(h+1,h+n+1);
	for(i=1;i<n;++i)d[i]=h[i+1]-h[i];
	for(i=1;i<n;++i)sd[i]=sd[i-1]+d[i];
	for(i=j=1,s=0;j<=n;++j){
		s+=d[j-1]*(j-i);
		while(s>m&&i<=j)s-=sd[j-1]-sd[i-1],++i;
		mx=max(mx,j-i+1);
	}
	cout<<mx<<"\n";
	return 0;
}
