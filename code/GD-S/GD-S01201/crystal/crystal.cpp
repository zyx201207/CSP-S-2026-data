#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],t[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		t[i]=t[i-1]+a[i];
		int l=0,r=i-1,mid,k=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(t[mid]-mid*a[i]<=t[i]-i*a[i]+m)r=(k=mid)-1;
			else l=mid+1;
		}ans=max(i-k,ans);
	}cout<<ans<<'\n';
	return 0;
}
