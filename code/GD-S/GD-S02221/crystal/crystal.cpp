#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],minv=1e18,mxv=-1e8,ans,maxv=-1e18;
int v[500010],s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		
		minv=min(minv,a[i]);
//		mxv=max(mxv,a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for (int i=1;i<=n;i++){
		v[i]=a[i]*i-s[i];
	}
	for (int i=n;i>=1;i--){
		if (v[i]<=m){
			cout<<i;
			return 0;
		}
	}
	
	

	
	
	
	
	
		
//	mid=mxv;
//	for (;mid>=minv;mid--){
//		
//		sort(a+1,a+n+1);
//		t=0;
//		ans=0;
//		for (int i=n;i>=1;i--){
//			//cout<<a[i]<<" ";
//			if (a[i]>mid) continue;
//			if (abs(mid-a[i])+t<=m){
//				t+=abs(mid-a[i]);
//				ans++;
//			}
//			else break;
//		}
//		//cout<<endl;
//		maxv=max(maxv,ans);
//	}
//	cout<<maxv;
	return 0;
}
