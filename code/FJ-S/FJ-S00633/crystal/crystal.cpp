#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i=n;i<=m;i++)
const int N=5e5+10;
#define int long long 
int n,m,a[N],pre[N],sum[N];
bool check(int len){
	rep(i,1,n-len+1){
		int j=i+len-1;
		//cout<<i<<' '<<j<<' '<<len<<' '<<a[j]<<'\n';
		if((a[j]*len-sum[j]+sum[i-1])<=m)return 1;
	}
	return 0;
}
void binary(){
	int mid,l=1,r=n,ans=1;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	rep(i,1,n){
		pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
		sum[i]=sum[i-1]+a[i];
	}
	binary();
	return 0;
}
