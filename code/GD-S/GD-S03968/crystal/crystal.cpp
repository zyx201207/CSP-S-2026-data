#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m,ans;
int a[N];
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2,sum=0;
		bool flag=0;
		for(int i=1;i<=n;i++){
			sum+=min(mid,i-1)*(a[i]-a[i-1]);
			if(i>mid) sum-=a[i]-a[i-mid];
			if(i>=mid && sum<=m) flag=1;
		}	
		if(flag) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	
	return 0;
}
