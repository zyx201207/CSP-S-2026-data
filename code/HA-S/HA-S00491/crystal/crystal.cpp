#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],ans;
bool check(int x){
	int sum=LONG_LONG_MAX;
	for(int i=1;i<=n-x+1;i++){
		sum=min(s[i+x-1]-s[i-1]-(i-1)*(a[i+x-1]-a[i-1]),sum);
	}
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
	int l=0,r=n,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
}
