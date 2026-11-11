#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,ans=0;
	for(int r=1;r<=n;r++){
		while(l<=r and (a[r]*(r-l+1)-(sum[r]-sum[l-1]))>m){
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
