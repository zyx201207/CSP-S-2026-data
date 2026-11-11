#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int a[N],dis[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)dis[i]=dis[i-1]+a[i];
	int r=0;
	for(int l=1;l<=n;l++){
		while(r<n&&(r-l+2)*a[r+1]-(dis[r+1]-dis[l-1])<=m)r++;
		ans=max(r-l+1,ans);
	}cout<<ans<<'\n';
	return 0;
}