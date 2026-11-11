#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],b[N];
int calc(int x){
	int l=1,r=x;
	while(l<=r){
		int mid=(l+r)>>1;
		int w=(a[x]*(x-mid+1)-(b[x]-b[mid-1]));
		if(w<=m) r=mid-1;
		else l=mid+1;
	}
	int w=(a[x]*(x-l+1)-(b[x]-b[l-1]));
	if(l==1) return x;
	return x-l+1+(m-w)/(a[x]-a[l-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++) ans=max(ans,calc(i));
	cout<<ans;
	return 0; 
}
