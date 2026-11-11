#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll m;
ll a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1;
	int ans=0;
	ll cnt=0;
	for(int r=1;r<=n;r++){
		cnt+=(a[r]-a[r-1])*(r-l);
		while(l<r and (cnt>m or cnt<0)){
			l++;
			cnt-=(a[r]-a[l]);
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
