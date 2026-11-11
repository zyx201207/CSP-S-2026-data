//GZ-S00017，刘书成，贵阳市南明区华麟学校
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll uj[600000];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);

    ll n,m,ma = 1;
    cin>>n>>m;

    for(ll i = 0;i<n;i++){
    	cin>>uj[i];
	}
	sort(uj,uj+n,cmp);

	ll t,st,ck,mm;
	for(ll i= 0;i<n;i++){
		t = m;st = 1;mm = i+1;ck = uj[i]-uj[mm];
		while(t>=ck&&mm<n){
			st++;mm++;t-=ck;
			ck = uj[i]-uj[mm];
		}
		ma = max(ma,st);
	}
	cout << ma;

    return 0;
}
