#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,ans;
int a[500005];
int tot[500005];
int sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[n]-a[i];
		sum[i]+=sum[i-1];
		tot[i]=a[n]-a[i];
	}
	int l=1,r=1;
	while(r<=n){
		if(sum[r]-sum[l-1]-tot[r]*(r-l+1)<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			l++;
		}
		if(r<l)r++;
	}
	cout<<ans<<endl;
	return 0;
} 
