#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=6e5+5;
int a[maxn],sum[maxn],m;

bool check(int l,int r){
	int tmp=1ll*a[r]*(r-l+1);
	tmp-=sum[r]-sum[l-1];
	if(tmp>m) return 0;
	else return 1;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int tot=0,ans;
	int n;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);sum[0]=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i))r=mid-1,ans=mid;
			else l=mid+1;
		}tot=max(tot,i-ans+1);
	}cout<<tot;
	return 0;
}
