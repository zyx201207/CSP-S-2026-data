#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
int sum[500005],num[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){num[i]=num[i-1]+(a[i]-a[i-1]);}
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int maxx=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,ans;
		while(l<=r){
			mid=(l+r)/2;
			int p=(num[i]-num[mid-1])*(mid-1);
			if(sum[i]-sum[mid]-p<=m){
				ans=i-mid+1;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
} 

