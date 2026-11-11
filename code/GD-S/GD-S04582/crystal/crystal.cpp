#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[5000001],s[5000001],maxn;
int sum(int l,int r){return s[r]-s[l-1];}
bool ss(int l,int r){return a[r]*(r-l+1)-sum(l,r)<=m;}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=n;i>=1;i--){
		int l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(!ss(l,r))l=mid+1;
			else r=mid-1;
		}
		maxn=max(maxn,i-mid+1);
	}
	cout<<maxn;
	return 0;
}
