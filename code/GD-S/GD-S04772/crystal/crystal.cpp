#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;
ll ttl[500007];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	ll x;
    	cin>>x;
    	a.push_back(x);
	}
	sort(a.begin(),a.end());
	ttl[0]=a[0];
	for(int i=1;i<n;i++){
		ttl[i]=ttl[i-1]+a[i];
	}
	int mx=1;
	for(int i=1;i<n;i++){
		int l=0;
		int r=i;
		int mid=(l+r)/2;
		while(l<r-1){
			mid=(l+r)/2;
			if(a[i]*(i-mid)-ttl[i-1]+ttl[mid-1]>m){  //mid unavailable
				l=mid;
			}
			if(a[i]*(i-mid)-ttl[i-1]+ttl[mid-1]<=m){  //mid available
				r=mid;
			}
		}
		if(l==0){
			if(a[i]*i-ttl[i-1]<=m){
				r=0;
			}
		}
		mx=max(mx,i-r+1);
	}
	cout<<mx;
	return 0;
}
