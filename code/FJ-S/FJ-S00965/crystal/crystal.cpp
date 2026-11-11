#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long l,r,mid;
long long a[500010];
bool check(int x){
	long long s=0;
	for (int i=1;i<x;i++) s+=(a[x]-a[i]);
	return s<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=2,r=n;
	while (l<=r){
		mid=(l+r)>>1;
		if (check(mid)){
			l=mid+1;
			ans=mid;	
		}
		else r=mid-1;
	}
	cout<<ans<<"\n";
	return 0;
}
