#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mx,a[500005],s[500005];
int ok(int x,int y){return m>=a[y]*(y-x)-s[y-1]+s[x-1];}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0),cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(ok(mid,i)) r=mid-1;
			else l=mid+1;
		}
		mx=max(mx,i-r);
	}
	return cout<<mx,0;
}
