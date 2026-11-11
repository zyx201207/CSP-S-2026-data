#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
bool f=1;
int t;
int sum[500005];
bool check(int tou,int mid){
	if(a[tou]*(tou-mid+1)-(sum[tou]-sum[mid-1])<=m){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}	
	sort(a+1,a+1+n);
	int ans=1;
		for(int i=n;i>=1;i--){
			int l,r;
			r=i;
			l=1;
			while(l<=r){
				int mid=l+r>>1;
				if(check(i,mid)){
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			ans=max(ans,i-r);
		}
	cout<<ans;
	return 0;
}