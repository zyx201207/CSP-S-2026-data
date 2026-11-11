#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int maxn=5e6+5;
int a[maxn],sum[maxn],n,m,ans=0;

inline int check(int l,int r){
	if(((r-l+1)*a[r]-(sum[r]-sum[l-1]))<=m) return 1;
	return 0;
}

inline void solve(int pos){
	int r=pos,l=1;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid,pos)){
			r=mid;
			//cout<<r" ";
		}else{
			l=mid+1;
			//cout<<l<<" ";
		}
	}
	int cur_ans=pos-l+1;
	//cout<<"pos = "<<pos<<" "<<"l = "<<l; 
	//是否要处理边界情况？如没有l合法 
	ans=max(ans,cur_ans);
}

signed main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		solve(i);
	}
	cout<<ans;
	return 0;
}
