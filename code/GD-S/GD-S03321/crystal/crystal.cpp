#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sa[500005],a[500005]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sa[i]=sa[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l<r){
			int mid=(l+r+1)/2;
			int p=a[i]*(r-l-1)-(sa[r-1]-sa[l]);
			if(p<=m){
				ans=max(ans,r-l);
				l=mid;
			}
			else r=mid;
		}
	}
	cout<<ans;
	return 0;
} 
