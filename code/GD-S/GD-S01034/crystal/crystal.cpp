#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+50;
ll n,m,f[maxn],sum[maxn];
bool check(int u){
	for(int l=1;l<=n-u+1;l++){
		int r=l+u-1;
		if(f[r]*(r-l+1)-(sum[r]-sum[l-1])<=m) return 1;	
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+f[i];
	int l=1,r=n,res=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1,res=mid;
		else r=mid-1;
	}
	cout<<res;
	return 0;
}
