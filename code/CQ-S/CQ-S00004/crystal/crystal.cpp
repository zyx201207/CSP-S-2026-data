#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cha[500005],sum[500005],sum2[500005],maxn;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cha[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+cha[i];
	}
	for(int i=1;i<=n;i++){
		sum2[i]=sum2[i-1]+sum[i];
	}
	for(int l=1;l<=n;l++){
		int l2=l,r2=n;
		while(l2<=r2){
			int mid=(l2+r2)/2;
			int sum3=0,x,y,z;
			if(l<2){
				x=0;
			}else{
				x=sum2[l-2];
			}
			if(mid<2){
				y=0;
			}else{
				y=sum2[mid-2];
			}
			if(mid<1){
				z=0;
			}else{
				z=sum[mid-1];
			}
			if((mid-l)*z-(y-x)<=m){
				l2=mid+1;
			}else{
				r2=mid-1;
			}
		}
		maxn=max(maxn,l2-l);
	}
	cout<<maxn;
	return 0;
}
