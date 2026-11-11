#include <bits/stdc++.h>
using namespace std;

namespace tymxz{
	const int N=5e5+7;
	typedef long long ll;
	typedef unsigned long long ull;
	int n;
	ll m;
	ll a[N],su[N];
	ull chk(int l,int r){
		return (ull)a[r]*(r-l+1)-(ull)(su[r]-su[l-1]);
	}
	void subt(){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) su[i]=su[i-1]+a[i];
		int mx=0;
		for(int i=1;i<=n;i++){
			int lb=1,ub=i,ans=1;
			while(lb<=ub){
				int mid=(lb+ub)>>1;
				if(chk(mid,i)<=m) ans=mid,ub=mid-1;
				else lb=mid+1;
			}
			mx=max(mx,i-ans+1);
		}
		cout<<mx<<endl;
	}
}
signed main(){
	freopen("crystal.in" ,"r",stdin );
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	tymxz::subt();
	return 0;
} 
