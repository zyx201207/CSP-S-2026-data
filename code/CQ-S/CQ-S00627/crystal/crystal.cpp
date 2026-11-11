#include <bits/stdc++.h> 
using namespace std;
int n;
long long m,sz[1000005],qzh[1000005];
int pd(int mi){
	for(int i=mi;i<=n;i++){
		if(1ll*sz[i]*mi<=qzh[i]-qzh[i-mi]+m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>sz[i];
	sort(sz+1,sz+n+1);
	for(int i=1;i<=n;i++)qzh[i]=qzh[i-1]+sz[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(pd(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
