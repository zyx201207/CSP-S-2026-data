#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int n,m;
ll a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i]; 
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)
				r=mid-1,res=mid;
			else
				l=mid+1;
		}
		ans=max(ans,(i-res+1));
//		cout<<i<<' '<<res<<endl;
	}
	cout<<ans<<endl;
	return 0;
} 
