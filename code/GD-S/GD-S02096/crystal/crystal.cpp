#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn],sum[maxn];
inline bool check(int pos,int lpos){
	if((pos-lpos+1)*a[pos]-(sum[pos]-sum[lpos-1])>m) return 0;
	return 1;
}
inline int solve(int ans){;
	int pos=ans;
	int l=1,r=ans+1;
	while(l<r){
		int mid=l+r>>1;
		if(check(pos,mid)) r=mid;
		else l=mid+1;
	}
	return pos-l+1;
}
int wc;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	bool flag1=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag1=0;
	}
	if(flag1){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	int l=1,r=n+1;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		wc=max(wc,solve(i));
	}
	cout<<wc;
	return 0;
}
