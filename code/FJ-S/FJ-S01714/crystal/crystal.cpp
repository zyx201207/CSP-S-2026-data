#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int n,m,a[N],pre[N],ans=1;
bool check(int mid,int i){
	return ((i-mid)*a[i]-(pre[i-1]-pre[mid-1])<=m);
}
signed main(){
	int i;
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(i=2;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i))r=mid-1,ans=max(ans,i-mid+1);
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
} /*
5 8
-3 -1 2 2 7
*/
