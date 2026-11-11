#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l,r,mid;
	for(int i=1;i<=n;i++){
		l=1,r=i;
		while(l<=r){
			mid=l+r>>1;
			if((i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m){
				ans=max(ans,i-mid+1),r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}