#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m;
long long a[N],sum[N];
void check(int x){
	int l=1,r=x,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(1ll*((x-mid+1)*a[x]-(sum[x]-sum[mid-1])) <= m){
			r=mid;
		}
		else l=mid+1;
	}
	ans=max(ans,x-r+1);
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		check(i);
	}
	cout<<ans;
}
