#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
ll n,a[maxn],sum[maxn],m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i;
		//cout<<"i"<<i<<" "<<'\n';
		while(l<r){
			int mid=(l+r)/2;
		//	cout<<l<<' '<<r<<' '<<mid<<' '<<sum[i-1]<<' '<<sum[mid-1]<<'\n';
			if(1ll*a[i]*(i-mid)-sum[i-1]+sum[mid-1]<=m)r=mid;
			else l=mid+1;
		}
	//	cout<<l<<'\n';
		ans=max(ans,1ll*i-l+1);
	}
	cout<<ans;
	return 0;
}
