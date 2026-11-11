#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;

const int N=5e5+5;

int n,k,ans,a[N],pre[N];

inline bool check(int l,int r){
	int tgt=a[r]*(r-l+1);
	int sum=pre[r]-pre[l-1];
	//cerr<<l<<' '<<r<<':'<<tgt-sum<<'\n';
	return sum+k<tgt;
}

inline int bf(int l,int r,int x){
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(x,mid)) r=mid-1;
		else l=mid;
	}
	return l;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fast;
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int res=bf(i,n,i);
		//cerr<<i<<' '<<res<<'\n';
		ans=max(ans,res-i+1);
	}
	cout<<ans;
	return 0;
}
