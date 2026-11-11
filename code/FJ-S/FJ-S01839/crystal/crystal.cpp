#include<bits/stdc++.h>
#define int long long
using namespace std;const int N=5e5+5;
int n,m,a[N],p[N],i,j,ans;
signed main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	for(cin>>n>>m,i=1;i<=n;cin>>a[i++]);
	for(sort(a+1,a+1+n),i=1,j=0;i<=n;i++){p[i]=p[i-1]+a[i];
		while((i-j)*a[i]-(p[i]-p[j])>m)j++;
		ans=max(ans,i-j);
	}return cout<<ans,0;
}
