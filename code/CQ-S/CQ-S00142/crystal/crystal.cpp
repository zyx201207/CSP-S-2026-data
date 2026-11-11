#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
using namespace std;
const int N=5e5+1;
ll n,k,ans,l,r,a[N];
inline bool chk(int m){
	ll res=0,sum=0;
	for(int i=1;i<=m;i++)sum+=a[m]-a[i];
	res=sum;
	for(int i=2;i+m-1<=n;i++){
		sum+=(a[i+m-1]-a[i+m-2])*m-(a[i+m-2]-a[i-1]);
		res=min(res,sum);
	}
	return res<=k;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1),l=1,r=n;
	while(l<=r){
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
/*
服了，开考一小时才发现只能加 1 

明明最后一场了，还在竞选高二最强乃龙 
*/
