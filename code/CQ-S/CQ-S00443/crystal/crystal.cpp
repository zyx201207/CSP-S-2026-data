#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r;ll s=0,ans=0;
	for(r=1;r<=n;r++){
		s+=(r-l)*(a[r]-a[r-1]);
		while(s>m&&l<r){
			s-=a[r]-a[l];
			l++;
		}
		if(s<=m)ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}

