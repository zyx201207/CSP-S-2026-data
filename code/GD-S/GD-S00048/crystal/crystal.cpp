#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,k,a[N],sum[N],ans,tmp;
bool check(int x){
	return (tmp-x)*a[tmp]-(sum[tmp-1]-sum[x-1])<=k;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,cnt=-1;
		tmp=i; 
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid))cnt=mid,r=mid-1;
			else l=mid+1;
		}
		if(cnt!=-1)ans=max(ans,i-cnt+1);
	}
	cout<<ans<<endl;
	return 0;
}
//服了，考前知道上午J组大概T1要挂个15分左右
//事已至此，先看T1吧
//这不一眼二分吗？ 
//应该能过吧 
//lyh居然压中题了还真是二分 
//15:02通过T1,我去我居然会做T1，不过这场比较简单 
