#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m;
int a[N];
int cnt[N];
int l;
int ans[30][N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		for(int k=30;k>=0;k--){
			if(a[i]&(1<<k)){
				ans[k][++cnt[k]]=a[i];
			}
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			int res=ans[i][1];
			for(int j=2;j<=m;j++) res&=ans[i][j];
			cout<<res;
			return 0;
		}
	}
	cout<<0;
	return 0;
}