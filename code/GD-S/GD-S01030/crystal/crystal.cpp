#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,a[N],m,sum[N];
int calc(int l,int i,int r){
	int tot=0;
	tot+=(sum[r]-sum[i]-(r-i)*a[i]);
	tot+=((i-l)*a[i]-(sum[i-1]-sum[l-1]));
	return tot;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		sum[i]=a[i]+sum[i-1];
	}
	int l=1,ans=0;
	for(int i=1;i<=n;++i){
		while(((i-l)*a[i]-(sum[i-1]-sum[l-1]))>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
