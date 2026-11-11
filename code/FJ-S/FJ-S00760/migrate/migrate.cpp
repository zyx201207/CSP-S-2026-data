#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
using namespace std;

const int N=2e6+5;

int GUNMU,T,n,k,a[N],lim[N],now,cnt;

inline void dfs(int l,int r,int stp){
	if(stp>now) return;
	if(l==r){
		if(stp==now) ++cnt;
		else now=stp,cnt=0;
		return;
	}
	for(int i=l;i<=lim[l];++i){
		dfs(i,r,stp+1);
	}
}

int main(){
	freopen("migrate1.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	fast;
	cin>>GUNMU>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;++i) cin>>a[i];
		int l,r;
		for(l=1,r=1;l<=n;++l){
			while(a[r]-a[l]<=k&&r<=n) ++r;
			--r;
			lim[l]=r;
		}
		int ans=0;
		for(int l=1;l<=n;++l){
			for(int r=1;r<=n;++r){
				now=0x7f7f7f7f,cnt=0;
				dfs(l,r,1);
				ans+=(cnt==2);
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

