//刘科 GZ-S00100 安顺市第二高级中学
#include<bits/stdc++.h>
#define int long long

using namespace std;
const int kMaxN=1e6+9;
int n,m,num[kMaxN],a[kMaxN],ans;
bool check(int con,int pl){
	int need=a[pl]*con-(num[pl]-num[pl-con]);
	if(need<=m){
		return 1;
	}else{
		return 0;
	}
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
		num[i]=num[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
	int l=1,r=i,mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid,i)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}

