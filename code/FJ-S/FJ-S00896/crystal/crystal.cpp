#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],ans=1,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) c[i]=c[i-1]+a[i];
	for(int i=2;i<=n;i++){
		long long ansl,l=1,r=i-1;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(c[i]-c[mid-1])<=m) ansl=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-ansl+1);
	}
	cout<<ans;
	return 0;
}

