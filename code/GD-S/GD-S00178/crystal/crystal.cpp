#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N],l,r,ans;
int check(int num){
	for(int i=num;i<=n;i++){
		if(a[i]*num-(sum[i]-sum[i-num])<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	l=0,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
