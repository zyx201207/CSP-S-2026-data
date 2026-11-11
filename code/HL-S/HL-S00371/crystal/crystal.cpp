#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll a[N];
int n,m;
int check(ll mid){
	int yu=0;
	int x=m;
	for(int i=n;i>=1;i--){
		if(a[i]>mid){
			continue;
		}else if(a[i]==mid){
			yu++;
		}else{
			if(mid-a[i]<=x){
				x-=(mid-a[i]);
				yu++;
			}
		}
	}
	return yu;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll zx=inf;
	ll zd=-inf+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zx=min(zx,a[i]);
		zd=max(zd,a[i]);
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(ll i=zx;i<=zd;i++){
		if(check(i)>ans){
			ans=check(i);
		}
	}
	cout<<ans;
	return 0;
}







 
