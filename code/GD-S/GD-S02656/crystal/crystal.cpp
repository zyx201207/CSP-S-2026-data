#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],res,pre[N];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	res=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-pre[i]+pre[mid-1]<=m){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		res=max(res,i-ans+1);
	}
	cout<<res;
	return 0;
}
