#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],sum[N];
int f(int l,int r,int k){
	int ls=l-1,rs=r;
	while(ls+1<rs){
		int mid=(ls+rs)/2;
		if(k*(r-mid)-(sum[r-1]-sum[mid-1])<=m)rs=mid; 
		else ls=mid;
	}
	return rs;
}
signed main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		ans=max(i-f(1,i,a[i])+1,ans);
	}
	cout<<ans;
	return 0;
} 
