#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int ans=0;
int sum[500010];
bool check(int mid,int r){
	if((r-mid+1)*a[r]-(sum[r]-sum[mid-1])<=m){
		return 0;
	}
	else return 1;
}

void f(int l,int r,int yr){
	while(l<=r){
		int mid=(r-l)/2+l;
		if(check(mid,yr)){
			l=mid+1;
		}else{
			ans=max(ans,yr-mid+1);
			r=mid-1;
		}
	}
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	for(int i=2;i<=n;i++){
		f(1,i-1,i);
	}
	cout<<ans;
	return 0;
}
