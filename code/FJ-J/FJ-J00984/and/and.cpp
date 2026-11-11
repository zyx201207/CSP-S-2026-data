#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,mx=-1;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll ma=1;
	for(ll i=1;i<=n;i++){
		ma*=2;
	}
	ma--;
	for(int i=1;i<=ma;i++){
		ll ii=i,ans=0,sum=ma,x=0;
		while(ii>0){
			x++;
			if(ii%2==1){
				sum=sum&a[x];
				ans++;
			}
			ii=ii>>1;
		}
		if(ans==m&&sum>mx) mx=sum;
	}
	cout<<mx;
    return 0;
}