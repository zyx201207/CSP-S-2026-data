#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500055],pre[2000550];
int n,m;
bool check(int x){
	int cnt=1e14+1;
	for(int i=x;i<=n;i++){
		cnt=min(cnt,x*a[i]-pre[i]+pre[i-x]);
		if(cnt<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	} 
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
}
 
