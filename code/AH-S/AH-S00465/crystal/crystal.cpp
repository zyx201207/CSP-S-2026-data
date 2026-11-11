#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int maxn=-LLONG_MIN,ans=-1,minn=LLONG_MAX;
int check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x)cnt+=x-a[i];	
	}
	return cnt;
}
int find_cnt(int x){
	int res=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x)res++;
	}
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	int l=minn,r=maxn;
	while(l<=r){
		int mid=l+r>>1;
//		cout<<l<<" "<<r<<" "<<mid<<" "<<check(mid)<<" "<<find_cnt(mid)<<endl;
		if(check(mid)<=m){
			ans=max(ans,find_cnt(mid));
			l=mid+1;
		}
		else if(check(mid)>m)r=mid-1;
	}
	cout<<ans;
	return 0;
} 
