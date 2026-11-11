#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],s[N];
inline bool check(int x){
	for(int i=x;i<=n;i++){
		ll need=a[i]*(ll)x-(s[i]-s[i-x]);
		if(need<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n,mid,ans=1;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
