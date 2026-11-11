#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,arr[214514];
bool check(int k){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(arr[i]>=k)cnt++;
	}
	return cnt>=m;
}
signed main(void){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int l=0,r=1e11;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	cout<<l-1;
	return 0;
}
