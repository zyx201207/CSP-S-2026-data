#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+4;
int a[N],q[N];
int n,m;
bool c(int len){
	for(int l=1;l+len-1<=n;l++){
		int r=l+len-1;
		if((a[r]*len-(q[r]-q[l-1]))<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(c(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
}