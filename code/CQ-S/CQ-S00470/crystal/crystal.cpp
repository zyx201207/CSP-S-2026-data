#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i]; 
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,ansi=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-1-mid+1)-(sum[i-1]-sum[mid-1])<=m){
				r=mid-1;
				ansi=mid;
			}else{
				l=mid+1;
			}
		}
		if(ansi==-1){
			ans=max(ans,(long long)1);
		}else{
			ans=max(ans,i-ansi+1);
		}
	}
	cout<<ans;
	return 0;
}
