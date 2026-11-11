#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],pre[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=0,r=i+1,mid=0;
		while(l+1<r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m)
				r=mid;
			else l=mid;
		} ans=max(ans,i-r+1);
	} cout<<ans;
	return 0;
} 
