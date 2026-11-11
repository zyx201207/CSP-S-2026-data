#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
long long n,m,a[N],sum[N],l,r,mid,ans;

bool check(long long x){
	for(int i=x;i<=n;i++){
		if(x*a[i]-sum[i]+sum[i-x]<=m){
			return 1;
		}
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	l=1;
	r=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
