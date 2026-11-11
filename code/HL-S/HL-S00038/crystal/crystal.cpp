#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=0,r=i-1,mid,res=i;
		while(l<=r){
			mid=(l+r)>>1;
			if((i-mid)*a[i]-(s[i]-s[mid])<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res);
	}
	cout<<ans<<'\n';
	return 0;
}