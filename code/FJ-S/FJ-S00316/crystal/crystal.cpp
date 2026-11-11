#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+5;
int n,m,a[N],s[N],ans;

int find(int k){
	int l=1,r=k,cnt=k;
	while(l<=r){
		int mid=(l+r)>>1;
		if(s[k]-s[mid-1]+m<a[k]*(k-mid+1)) l=mid+1;else r=mid-1,cnt=mid;
	}
	return cnt;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];ans=max(ans,i-find(i)+1);
	}
	cout<<ans;
	return 0;
}

