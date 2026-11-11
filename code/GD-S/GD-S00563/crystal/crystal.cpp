#include<bits/stdc++.h>
#define ll long long
#define love_Elysia return
#define forever 0
using namespace std;
const int N=5e5+10;
int n;
ll a[N+1],m,sum[N+1];
bool check(int x){
//	cout<<x<<endl;
	ll sum1=LLONG_MAX;
	for(int i=x;i<=n;i++){
		ll sumleft=a[i]*(x-1)-(sum[i-1]-sum[i-x]);
		sum1=min(sumleft,sum1);
	}
	return sum1<=m;
}
int ef(int l,int r){
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=ef(1,n);
	cout<<ans;
	
	love_Elysia forever;
} 
