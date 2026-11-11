#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long n,m,a[N],ans,d[N],l,r,mid;
bool check(int k){
	for(int i=1,j=k;j<=n;i++,j++) if(a[j]*k-(d[j]-d[i-1])<=m) return true;
	return false;
} 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);l=1,r=n;for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}cout<<ans<<'\n';
	return 0;
}
