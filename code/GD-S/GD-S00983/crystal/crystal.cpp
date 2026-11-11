#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m;
ll a[N];
ll b[N];
ll sum[N];
ll mx=0;
bool check(int x){
	ll cnt=0;
	if(x>n-1) return 0;
	for(int i=1;i<=x;i++) cnt+=i*b[i];
	if(cnt<=m) return 1;
	for(int i=x;i<n-1;i++){
		cnt=cnt-sum[i]+sum[i-x+1]+b[i+1]*x;
		if(cnt<=m) {
			return 1;
		}
	}
	return 0;
}




void solve(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
//		cout<<b[i-1]<<" ";
		sum[i-1]=sum[i-2]+b[i-1];
	}
	
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	
	cout<<ans+1<<endl;//本身自带一个 
	//14:51 
	//忘记加sum[i-x+1]了，15:15 
	
	
	return ;
}


int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	
	
	return 0;
}
