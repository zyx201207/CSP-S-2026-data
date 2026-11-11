#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sm[N],st[N][20],lgn[N];
bool ck(int x){
	for(int i=1;i+x-1<=n;i++){
		int yuy=max(st[i][lgn[x]],st[i+x-(1<<lgn[x])][lgn[x]]),klo=sm[i+x-1]-sm[i-1],nd=yuy*x-klo;
		if(nd<=m) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sm[i]=sm[i-1]+a[i],st[i][0]=a[i];
	for(int j=1;j<=19;j++)
		for(int i=1;i+(1<<j)-1<=n;i++) st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int i=2;i<=n;i++) lgn[i]=lgn[i>>1]+1;
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ck(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
/*
use 46 min
*/
