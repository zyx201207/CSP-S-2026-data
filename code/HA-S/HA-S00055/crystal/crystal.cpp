#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+5;
int a[N],sum[N];
//考虑二分答案，然后滑动窗口，没了
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		if(a[i+x-1]*x-sum[i+x-1]+sum[i-1]<=m)return true;
	}
	return false;
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	} 	
	cout<<ans;
	return 0;
}

