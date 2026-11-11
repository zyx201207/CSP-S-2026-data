#include<bits/stdc++.h>
#define LL long long
#define P(i,s,t) for(int i=s;i<=t;++i)
#define S(i,s,t) for(int i=s;i>=t;--i)
using namespace std;
const int N=5e5+5;
int n;
LL m,a[N],sum[N],l,r,mid,res,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	P(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	P(i,1,n) a[i]=a[n]-a[i],sum[i]=sum[i-1]+a[i];
	P(i,1,n){
		l=0,r=i-2,res=i-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(sum[i]-sum[mid]-(i-mid)*a[i]<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res);
	}
	cout<<ans;
	
	return 0;
}
