#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10000005],f[10000005];
int n,m;
bool check(int k){
	if(k==1) return 1;
	for(int j=k;j<=n;++j){
		int maxn=a[j-1];
		int pre=f[j-1]-f[j-k];
		int cost=(k-1)*maxn-pre;
		if(cost<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i+1]=f[i]+a[i];
	}
	int l=1,r=n;
	int ans=1;
	while(l<=r){
		int mid=l+(r-l)/2;
		//int cost=mid*a[mid]-f[mid];
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
		//cout<<l<<r;
	}
	cout<<ans;
	return 0;
}
