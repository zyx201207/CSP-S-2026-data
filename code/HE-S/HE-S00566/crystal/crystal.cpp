#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int n,m;

bool cmp(int x,int y) {
	return x<y;
}

bool chack(int x){
	int mx=m;
	for(int i=x;i>=1;i--){
		if(a[x]-a[i]>mx||mx<0){
			return 0;
		}else{
			mx-=(a[x]-a[i]);
		}
	}
	return 1;
}

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=n,mid;
	int ans=0;
	while(l<r){
		mid=(l+r)/2;
		if(chack(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
