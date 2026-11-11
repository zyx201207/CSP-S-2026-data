#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],b[500005]; 
bool check(int x){
	int res=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n-x+1;i++){
		res=min(res,a[i+x-1]*x-b[i+x-1]+b[i-1]);
	}
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int l=0,r=n+1;
	while(l+1!=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}

