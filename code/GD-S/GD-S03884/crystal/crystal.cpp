#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],p[N],ans=1;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) p[i]=p[i-1]+a[i];
	int l=1;
	for(int r=2;r<=n;++r){
		while((r-l)*a[r]-(p[r-1]-p[l-1])>m&&l<r){
			++l;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
