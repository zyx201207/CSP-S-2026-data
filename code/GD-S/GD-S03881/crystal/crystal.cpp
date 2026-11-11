#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5,M=1e12;
ll n,m,ans,a[N],s[N];
bool chk(int i,ll mid,ll need){
	ll sum=(s[i-1]-s[mid-1]);
	return need-sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=M;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ans=1;
	for(int i=2;i<=n;i++){
		ll l,r,mid,res,need;
		l=1,r=i,res=-1;
		while(l<r){
			mid=(l+r)>>1;
			need=a[i]*(i-mid);
			if(chk(i,mid,need)){
				r=mid;
				res=mid;
			}else l=mid+1;
		}
		if(res!=-1) ans=max(ans,i-res+1);
	}
	cout<<ans<<"\n";
	return 0;
}
