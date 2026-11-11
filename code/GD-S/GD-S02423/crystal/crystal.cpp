#include<bits/stdc++.h> 
using namespace std;
#define int long long
int n,m,a[500005],d[500005];
int s[500005],sum[500005];

bool check(int k){
	int minn=1e18;
	for(int i=1;i+k<=n;i++){
		int w=sum[i+k-1]-sum[i-1]-(i-1)*(a[i+k]-a[i]);
		minn=min(minn,w);
	}
	return minn<=m;
}

int f(int m){
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)){
			l=mid;
		}else r=mid-1;
	}
	return l;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++) sum[i]=sum[i-1]+i*d[i];
	cout<<f(m)+1;
	return 0;
}
