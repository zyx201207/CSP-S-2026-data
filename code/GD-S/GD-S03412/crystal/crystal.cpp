#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[500005],sum[500005];
inline bool check(int x,int y){
	int cnt=0;
	cnt+=a[y]*(y-x);
	cnt-=(sum[y-1]-sum[x-1]);
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int num=a[1];
	for(int i=1;i<=n;i++)a[i]-=num;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
} 
