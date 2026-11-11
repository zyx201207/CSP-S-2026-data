#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans;
ll m,a[500005],sum[500005];
bool check(int i,int j){
	int tot=j*a[i]-(sum[i]-sum[i-j]);
	return tot<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i,res=1;
		while(l<=r){
			int mid=l+r>>1;
			if(check(i,mid)) res=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}
// 哇！哇！哇！调了快 3 个小时终于过了！
