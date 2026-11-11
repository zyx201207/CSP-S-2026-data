#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],b[N],c[N];
bool check(int x){
	for(int i=x;i<=n;++i){
		if(b[i]*(x-1)-c[i-1]+c[i-x]<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		b[i]=a[i]-a[1];
		c[i]=c[i-1]+b[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0; 
}

