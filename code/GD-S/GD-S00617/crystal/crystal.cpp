#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,m;
int a[N];
int chs1[N],p,ans[N],l,chs2[N];
bool dfs(int k){
	for(int i=1;i<=n-k+1;i++){
		int l=i,r=i+k-1,s=ans[r]-chs1[l-1]+chs2[r]*(l-1);
		if(s<=m){
			return true;
		}
	}
	return false;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)p+=(a[i]-a[i-1]);
	for(int i=1;i<=n;i++)
		chs1[i]=chs1[i-1]+p,p-=(a[i+1]-a[i]);
	for(int i=2;i<=n;i++)
		ans[i]=ans[i-1]+(a[i]-a[i-1])*(++l);
	for(int i=n-1;i>=1;i--)
		p+=(a[i+1]-a[i]),chs2[i]=p;
	l=0;
	int L=1,R=n;
	while(L<R){
		int mid=(L+R)>>1;
		if(dfs(mid)){
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	printf("%lld",L-1);
	return 0;
}
