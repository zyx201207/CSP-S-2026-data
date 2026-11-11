#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N],ans,d[N],d2[N],d3[N],d4[N],d5[N]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
		d2[i]=d2[i-1]+d[i];
		d3[i]=d3[i-1]+d2[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)>>1;
			//cout<<((i-1)*d2[i-1]-d3[max(i-2,0ll)])-(max(i-mid-1,0ll)*d2[max(i-1,0ll)]-d2[max(i-mid-2,0ll)])<<" "<<i<<" "<<mid<<endl;
			if(((i-1)*d2[i-1]-d3[max(i-2,0ll)])-(max(i-mid,0ll)*d2[max(i-1,0ll)]-d3[max(i-mid-1,0ll)])<=m) l=mid+1,ans=max(ans,mid);
			else r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
