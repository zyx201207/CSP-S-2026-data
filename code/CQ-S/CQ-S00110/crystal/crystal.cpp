//注意开long long 
//ai可以是负数
//30min发现过不了3，4
//原来是没排序就求前缀和了 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],sum[N],ans;
bool check(int l,int r){
	if((((r-l+1)*a[r])-(sum[r]-sum[l-1]))<=m)return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1ll;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid-1;
				ans=max(ans,i-mid+1);
				//cout<<mid<<' '<<i<<endl;
			}
			else{
				l=mid+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
