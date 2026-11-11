#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=5e5+10;
ll n,m;
ll a[N];
ll pre[N];
ll sum[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	sum[1]=0;
	for(int i=2;i<=n;i++){
		sum[i]=a[i]*(i-1)-pre[i-1];
	}
	ll l=1,r=1,ans=0;
	while(l<=r && r<=n){
		ll need=sum[r]-(a[r]*(l-1)-pre[l-1]);
		if(need>m){
			l++;
		}else{
			ans=max(ans,r-l+1);
			r++;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 3 5 8 9


*/
