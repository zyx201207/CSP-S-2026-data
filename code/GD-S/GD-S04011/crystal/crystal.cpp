#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 500010
#define ll long long
using namespace std;
int n,ans;
ll m,a[N],s[N];
bool ck(ll l,ll r){
	if(1ll*(r-l+1)*a[r]-(s[r]-s[l-1])<=m)return true;
	return false;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ans=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int p=i,l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(ck(mid,i))p=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-p+1); 
	}
	cout<<ans;
	return 0;
} 
