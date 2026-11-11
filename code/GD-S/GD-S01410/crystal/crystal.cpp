#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=1e18,INF=1e12;
int n,m,ans=0,minn=INF;
int a[N];
int cnt[N],sum[N];
bool check(int k){
	for(int i=1;i+k-1<=n;i++){
		int l=i,r=i+k-1;
		int pos=cnt[r]-(a[r]-a[l])*(l-1)-cnt[l];
		if(pos<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		cnt[i]=a[i]*(i-1)-sum[i-1];
		if(cnt[i]<=m) ans=max(ans,i);
	}
	int l=2,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
