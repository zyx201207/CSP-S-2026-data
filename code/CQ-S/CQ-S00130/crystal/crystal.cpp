#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],ans=1,b[500005],n,m;
int check(int k,int i){
	int sum=k*a[i]-(b[i-1]-b[i-k-1]);
	return sum;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=n;i>=1;i--){
		int l=1,r=i-1;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)<=m){
				ans=max(ans,mid+1);
				l=mid+1;
			}else r=mid-1;
		}
	}cout<<ans;
	return 0;
}
