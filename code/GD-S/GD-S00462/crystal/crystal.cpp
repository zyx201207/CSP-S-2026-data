#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int ans;
int sum[N];
bool check(int p){
	for(int i=1;i+p-1<=n;i++){
		int j=i+p-1;
		int res=0;
		for(int k=i;k<=j;k++){
			res+=a[j]-a[k];
		}
		if(res<=m){
			return true;
		}
	}
	return false;
}
void bs(){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))ans=max(ans,mid),l=mid+1;
		else r=mid-1;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bs();
	cout<<ans;
	return 0;
}
