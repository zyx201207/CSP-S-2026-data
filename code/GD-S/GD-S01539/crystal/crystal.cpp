#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+n+1);
	
	int ans=1;
	int l=1,sum=0;
	for(int r=2;r<=n;r++){
		sum+=(r-1-l+1)*(a[r]-a[r-1]);
		while(l<r&&sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
