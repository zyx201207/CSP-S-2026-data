#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node{
	ll x,y;
}b[2000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m,a[2000005];
	cin>>n>>m;
	for(ll i=1;i<=m;i++) b[i].x=i;
	sort(a,a+n);
	for(ll i=0;i<n;i++){
		for(ll j=1;j<=m;j++){
			if(a[i]==b[j].x) b[j].y++;
		}
	}for(ll i=1;i<=m;i++) cout<<b[i].y<<' ';
	return 0;
}