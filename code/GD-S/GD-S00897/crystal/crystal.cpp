#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=5e5+10; 
ll a[N],pre[N];
int n;
ll m;
ll calc(int i,int mid){
	return a[i]*(i-mid)-(pre[i-1]-pre[mid-1]);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=1,r=i-1,res=0;
		while(l<=r){
			int mid=l+r>>1;
			ll check=calc(i,mid);
			if(check>m) l=mid+1;
			else r=mid-1,res=mid;
		}
		if(res) ans=max(ans,i-res+1);
//		if(res) cout<<i<<" "<<res<<"\n";
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
}
/*
5 5
1 2 4 8 9
3

5 8
-3 -1 2 2 7
4
*/
