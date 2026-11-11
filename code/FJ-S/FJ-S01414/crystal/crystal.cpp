#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],sum[N],ma;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		if(a[i]*(i-l)-(sum[i-1]-sum[l-1])>m) l++;
		ma=max(ma,i-l+1);
	}
	cout<<ma;
	return 0;
} 
