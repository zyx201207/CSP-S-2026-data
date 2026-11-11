#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;

int n,m,ans;
int a[N];
int dp[N];
int sum[N][50];

int s(int l,int r){
	int res=0;
	for(int i=30;i>=1;i--){
		res+=((sum[r][i]-sum[l-1][i])>=(r-l+1));
		res=(res<<1);
	}
	res=(res>>1);
	return res;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int t=a[i],j=1;
		while(t>0){
			sum[i][j]=(t&1);
			t=(t>>1);
			j++;
		}
		for(int k=1;k<=30;k++){
			sum[i][k]+=sum[i-1][k];
		}
	}
	
	
	for(int i=m;i<=n;i++) ans=max(ans,s(i-m+1,i));
	cout<<ans;
}

signed main(){
	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	int TTT=1;
//	cin>>TTT;
	while(TTT--){
		solve();
	}
}