#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
ll n,m;
ll a[N];
ll sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int as=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(1ll*mid*a[i]-sum[i]+sum[i-mid]<=m) as=mid,l=mid+1;else r=mid-1; 
		}
		ans=max(ans,as);
	}
	cout<<ans<<endl;
	return 0;
}

