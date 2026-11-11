#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010],f[500010];
bool check(int x){
	int minn=LLONG_MAX;
	for(int i=x;i<=n;i++){
		a[0]=a[i];
		minn=min(minn,f[i]-(a[i]-a[i-x]));
	}
	return minn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l=1,r=n,mid;
	while(l+1<r){
		mid=l+r>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}//315275
