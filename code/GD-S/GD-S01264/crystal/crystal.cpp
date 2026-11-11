#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans=1,pfx[N],vis[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		int sum=pfx[i]-pfx[i-x],change=a[i]*x;
		change-=sum;
		if(change<=m){
			return 1;
		}
	}
	return 0;
}
void f(int l,int r){
	int mid;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pfx[i]=pfx[i-1]+a[i];
	f(2,n);
	cout<<ans;
	return 0;
}
