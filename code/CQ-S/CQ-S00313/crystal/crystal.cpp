#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,x,y) for(int i=x;i<=y;++i)
#define ff(i,x,y) for(int i=x;i>=y;--i)
#define clean(arr,val) memset(arr,val,sizeof(arr))
#define fi first
#define se second
#define lb(x) (x&-x)
#define bp(x) __builtin_popcount(x)
#define endl '\n'
const int N=5e5+5; 
int n,m,a[N],sum[N];
bool check(int x){
	int mm=1e18;
	f(i,x,n){mm=min(mm,a[i]*x-sum[i]+sum[i-x]);}
	return mm<=m;}
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	f(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	f(i,1,n){sum[i]=sum[i-1]+a[i];}
	int l=1,r=n,ans=1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<ans;
	return 0;	
}
