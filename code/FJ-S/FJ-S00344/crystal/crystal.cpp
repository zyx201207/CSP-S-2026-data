#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],pre[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r>>1);
			if(a[i]*(i-mid)-pre[i-1]+pre[mid-1]<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
