#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sug=5e5+5;
int n,m,ans;
int a[sug],sum[sug];
bool check(int x,int y){
	return (x-y+1)*a[x]-(sum[x]-sum[y-1])<=m;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sg=a[1];
	for(int i=1;i<=n;i++) if(sg<0) a[i]+=-1*sg;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
//			cout<<l<<" "<<mid<<" "<<r<<"\n";
			if(check(i,mid)) r=mid;
			else l=mid+1;
		}
		if(check(i,l)) ans=max(ans,i-l+1);
		else if(check(i,mid)) ans=max(ans,i-mid+1);
		else if(check(i,r)) ans=max(ans,i-r+1);
//		cout<<l<<" "<<mid<<" "<<r<<"\n\n";
	}
	cout<<ans;
	return 0;
}
