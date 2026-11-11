#include<bits/stdc++.h>
#define ll long long
#define N 500001
using namespace std;
ll n,m,a[N],sum[N],l,r,mid,now,res,ans=1;
map<ll,ll> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	if(i==1||a[i-1]!=a[i]){
		l=0;
		r=i-1;
		res=-1;
		while(l<=r){
			mid=(l+r)/2;
			if(mid*a[i]-sum[i-1]+sum[i-mid-1]<=m){
				l=mid+1;
				res=mid;
			}else r=mid-1;
		}
		if(res!=-1) ans=max(ans,mp[a[i]]+res);
	}
	cout<<ans<<endl;
	return 0;
} 
