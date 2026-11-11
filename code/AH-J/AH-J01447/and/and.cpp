#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
		cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    ll k=a[n--];
    for(ll i=1;i<m;i++){
		k&=a[n--];
	}
	cout<<k;
    return 0;
}
