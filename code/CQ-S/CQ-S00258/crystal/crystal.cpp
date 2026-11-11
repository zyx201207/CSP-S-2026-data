#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],mx;
bool check(int l,int r){
	if(a[r]*(r-l+1)-sum[r]+sum[l-1]<=m)return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)){
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
	return 0;
}

