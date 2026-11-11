#include<bits/stdc++.h>
using namespace std;
#define int long long
int T=1,n,m,ans=0;
int a[500005];
int p[500005];

bool check(int x){
	for(int i=x;i<=n;i++){
		int cnt=0;
		for(int j=i;j>=i-x+1;j--){
			cnt+= p[j]*(j-(i-x+1));
		}
		if(cnt<=m)return true;
	}
	return false;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool f=1;
	for(int i=2;i<=n;i++){
		p[i]=a[i]-a[i-1];
		if(p[i]!=p[i-1]&&i>=3)f=0;
	}
	if(f){
		int t=p[2];
		for(int i=1;i<=n;i++){
			if(m>=(i-1)*t){
				ans++;
				m-=(i-1)*t;
			}
		}
		cout<<ans;
	}else{
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<ans;
	}
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
