#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],vis[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		if(mx<(1<<i))continue;
		int cnt=0;
		for(int j=1;j<=n;j++)if(((a[j]>>i)&1)&&(!vis[j]))cnt++;
		if(cnt>=m){
			ans=(ans<<1)+1;
			for(int j=1;j<=n;j++)if(!((a[j]>>i)&1))vis[j]=1;
		}
		else ans<<=1;
	}
	cout<<ans;
	return 0;
}
