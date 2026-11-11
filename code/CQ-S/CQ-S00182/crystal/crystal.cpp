#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+3;
int n,m,a[N],s[N],l,r,mid,ans;
bool check(int l,int r){
	int x=(r-l+1)*a[r]-s[r]+s[l-1];
	return x<=m;
}signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;for(int i=1;i<=n;++i)cin>>a[i];
	sort(1+a,1+a+n);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		l=0,r=i;
		while(l<r){
			mid=(l+r+1)>>1;
			if(check(mid,i)) r=mid-1;
			else l=mid;
		}ans=max(ans,i-r);
	}cout<<ans;return 0;
}
