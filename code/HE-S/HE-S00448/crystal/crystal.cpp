#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
#define il inline
int n;
int m;
int a[N],sum[N];
int ans;
void solve(int bg,int ed){
	int l=1,r=bg,res=bg;
	while(l<=r){
		int mid=l+r>>1;
		if((a[ed]*(bg-mid))-(sum[bg-1]-sum[mid-1])<=m) r=mid-1,res=mid;
		else l=mid+1;
	}
	ans=max(ed-res+1,ans);
//	cout<<bg<<' '<<ed<<' '<<res<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	{
		int l=1,r=0;
		while(l<=n){
			while(r+1<=n&&a[l]==a[r+1]) ++r;
			solve(l,r);
			for(int i=l;i<=r;i++) sum[i]=sum[i-1]+a[i];
			l=r+1;
		}
	}
	cout<<ans;
	return 0;
}


