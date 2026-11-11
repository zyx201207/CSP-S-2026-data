#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m;
int a[N];
int ans=-1;
int sum[N];
int ck(int x,int y){
	return a[y]*(y-x+1)-(sum[y]-sum[x-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(a[i+1]==a[i]) i++;
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(ck(mid,i)<=m) ans=max(ans,i-mid+1),r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
} 

