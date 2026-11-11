#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],b[N],c[N],csum[N],ans;
int query(int l,int r){
//	cout<<l<<","<<r<<":"<<csum[r]-csum[l-1]-(a[r+1]-a[l])<<endl;
	return csum[r]-csum[l-1]-(l-1)*(a[r+1]-a[l]);
}
signed main(){
	freopen("crystal.in","r",stdin);
//	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++) b[i]=a[i+1]-a[i];
	for(int i=1;i<=n-1;i++) c[i]=b[i]*i,csum[i]=csum[i-1]+c[i];
//	for(int i=1;i<=n-1;i++) cout<<b[i]<<" "<<c[i]<<" "<<csum[i]<<endl;
	for(int i=1;i<=n-1;i++){
		int l=i,r=n-1,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(query(i,mid)<=m){
				res=mid;
				l=mid+1;
			}else r=mid-1;
		}
		ans=max(ans,res-i+1);
	}
	cout<<ans+1;
	return 0;
} 
