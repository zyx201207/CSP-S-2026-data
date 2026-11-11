#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int he[500005];
int checker(int l,int r){
	int sum=(r-l+1)*a[r];
	int now=he[r]-he[l-1];
	int nd=sum-now;
	if(nd<=m) return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) he[i]=he[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,Ans=i;
		while(l<=r){
			int mid=l+r>>1;
			if(checker(mid,i)==1) r=mid-1,Ans=mid;
			else l=mid+1;
		}
		ans=max(ans,i-Ans+1);
	}
	cout<<ans;
	return 0; 
} 
/*
5 8
-3 -1 2 2 7
*/
