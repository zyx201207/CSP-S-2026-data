#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,ans;
vector<ll> a;
bool check(int len){
	ll sum=0,minn=0;
	for(int j=1;j<len;j++) sum+=a[len]-a[j];
	minn=sum;
	for(int i=2;i+len-1<=n;i++){
		int j=i+len-1;
		sum-=a[j-1]-a[i-1];
		sum+=(a[j]-a[j-1])*(len-1);
		minn=min(minn,sum);
	}
	return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	a.resize(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	int l=1,r=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
