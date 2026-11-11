#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010101;
ll n,m,a[N],sum[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]||i==n){
			ll l=1,r=i;
			while(l<r){
				ll mid=l+r>>1;
				if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)r=mid;
				else l=mid+1;
			}
			ans=max(ans,i-r+1); 
		}
	}
	cout<<ans; 
	return 0;
} 
