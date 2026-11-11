#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int ans,d[N],vis; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]) vis++;
	}
	if(vis==n){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int sum=0,mx=0;
		for(int j=i;j>=1;j--){
			if(a[j]==a[i]){
				mx++;
				continue;
			}
			if(sum+(a[i]-a[j])<=m){
				sum+=(a[i]-a[j]);
				mx++;
			}
		}
		ans=max(ans,mx);
	}
	cout<<ans;
	return 0;
}
