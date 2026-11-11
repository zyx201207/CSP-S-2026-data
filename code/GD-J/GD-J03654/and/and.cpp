#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
ll ans[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll maxx=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			for(int d=0;d<n-j;d++){
				if(a[i]&a[d]>maxx){
					maxx=(a[i]&a[d]);
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}
