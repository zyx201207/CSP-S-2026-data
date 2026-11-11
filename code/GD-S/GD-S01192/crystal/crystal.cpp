#include<bits/stdc++.h>
using namespace std;
void file(string x){
	freopen((x+".in").data(),"r",stdin);
	freopen((x+".out").data(),"w",stdout);
} 
#define int long long
const int maxn=5e5+10;
int n,m,a[maxn], sum[maxn];
signed main(){
	file("crystal");
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=0,r=i;
		while(r-l>1){
			int mid=l+r>>1;
			if(mid*a[i]-(sum[i-1]-sum[i-mid-1])<=m)l=mid;
			else r=mid;
		}
		ans=max(ans,l+1);
	}
	cout<<ans;
	return 0;
}
