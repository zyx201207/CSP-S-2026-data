#include<bits/stdc++.h>
using namespace std;
const int NUM=5e5+10;
#define int long long

int n,m;
int a[NUM],x[NUM],s[NUM],sum[NUM];

int Sum(int l,int r){
	return sum[l]-s[r+1]*(r-l+1)-sum[r+1];
}

int bound(int i){
	if(i==0) return 0;
	int l=1,r=i,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(Sum(mid,i)<=m) r=mid-1,ans=mid;
		else l=mid+1;
	}
	return ans;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	a[n+1]=a[n];
	for(int i=1;i<=n;++i) x[i]=a[i+1]-a[i];
	for(int i=n;i>=1;--i) s[i]=s[i+1]+x[i];
	for(int i=n;i>=1;--i) sum[i]=sum[i+1]+s[i+1]+x[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		int pos=bound(i-1);
		ans=max(ans,i-pos+1);
	}
	cout<<ans<<'\n';
	return 0;
}
