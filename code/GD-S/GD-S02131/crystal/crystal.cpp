#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define int long long
const int N=5e5+10;
int n,m,a[N],sum[N],ans;
bool check(int x,int y){return a[y]*(y-x+1)-(sum[y]-sum[x-1])<=m;}
int sol(int x){
	int l=1,r=x,res=x;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,x)) res=mid,r=mid-1;
		else l=mid+1;
	}
	return x-res+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	REP(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	REP(i,1,n) sum[i]=sum[i-1]+a[i];
	REP(i,1,n) ans=max(ans,sol(i));
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
