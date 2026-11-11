#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],pre[500005];
int n,m;
int find(int l,int r,int x){
	int mid;
	while(l<r){
		mid=(l+r)/2;
		if(a[x]*(x-mid+1)-(pre[x]-pre[mid-1])>m)l=mid+1;
		else r=mid;
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;++i){
		ans=max(ans,i-find(1,i,i)+1);
	}
	cout<<ans;
	return 0;
}
