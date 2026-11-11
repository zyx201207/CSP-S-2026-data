#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0,a[500010],s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]*(mid-i+1)-(s[mid]-s[i-1])>m) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,r-i+1);
	}
	cout<<ans;
	return 0;
}
//15:03  100
