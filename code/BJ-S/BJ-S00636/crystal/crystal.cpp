#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010];
bool chk(int x){
	int sum=0;
	for(int i=1;i<x;i++){
		sum+=a[x]-a[i];
		if(sum>m) return 0;
	}
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
