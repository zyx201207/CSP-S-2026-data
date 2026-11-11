#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,w[500005],n,a[505][505],t[505][505],c,n,m,d,q,tmp,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>tmp;
		for(ll j=1;j<=tmp;j++)cin>>a[i][j]>>t[i][j];
	}for(ll i=1;i<=q;i++){
		cin>>x>>y;
	}
	return 0; 
}//Doing...
