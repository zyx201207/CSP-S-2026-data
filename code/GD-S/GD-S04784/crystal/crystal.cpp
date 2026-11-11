#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int a[N],c[N];

int dj(int l,int r){	
	return c[r]-c[l]-(a[r]-a[l])*(l-1);
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) c[i]=a[i]-a[i-1],c[i]=c[i-1]+(i-1)*c[i];
	
	int l=1,r=1;
	while(l<=n && r<=n && l<=r){
		if(dj(l,r)<=m){
			ans=max(ans,r-l+1);
			r++;
		}else l++;
	}
	cout<<ans<<'\n';
	return 0;
}
