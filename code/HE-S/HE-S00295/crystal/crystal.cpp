#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[600006],sum[600006],ans;
bool ck(int x,int r){
	int s=sum[r]-sum[r-x]+m,s2=a[r]*x;
	return s>=s2;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=n;i>=1;i--){
		int l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(ck(mid,i)){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,r);
	}
	cout<<ans<<'\n';
 } 
