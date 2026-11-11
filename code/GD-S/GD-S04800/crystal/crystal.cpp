#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+3;
ll n,m;
ll num[N],sum[N];
bool check(int dis){
	for(int i=1;i+dis-1<=n;i++){
		int b=i+dis-1;
		if(dis*num[b]-sum[b]+sum[i-1]<=m) return 1;
	}
	return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+num[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in", " r",stdin);
	freopen("crystal.out", " w",stdout);
	solve();
	return 0;
}



