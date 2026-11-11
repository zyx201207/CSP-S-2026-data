#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;

int n,m,l,sum,ans;
int a[N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	l=1;
	for(int r=2;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m&&l<r){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	int TTT=1;
//	cin>>TTT;
	while(TTT--){
		solve();
	}
}