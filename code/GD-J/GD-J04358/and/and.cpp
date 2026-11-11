#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e3+5;
int n,m,a[N],ans=0,sum2,mx=-2e9,mxsum;
void dfs(int idx,int cnt,int sum){
	if(cnt==m){
		if(idx==n+1) ans=max(ans,sum);
		return;
	}
	if(idx==n+1) return;
	if(cnt==0) {
		dfs(idx+1,cnt+1,a[idx]);
		dfs(idx+1,cnt,sum);
	}
	else {
		dfs(idx+1,cnt+1,sum&a[idx]);
		dfs(idx+1,cnt,sum);
	}
}
bool f=1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		mx=max(a[i],mx);
		if(i==1) mxsum=a[1];
		else mxsum&=a[i];
	}
	
	if(n==m){
		sum2=a[1];
		for(int i=2;i<=n;i++){
			sum2&=a[i];
		}
		cout<<sum2;
		return 0;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==2){
		int ans2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans2=max(ans2,a[i]&a[j]);
			}
		}
		cout<<ans2;
		return 0;
	}
	if(m==n-1){
		int mxans;
		for(int i=1;i<=n;i++){
			if(i==1) mxans=mxsum|a[1];
			else mxans=max(mxsum|a[i],mxans);
		}
		cout<<mxans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
