#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],c[N],s[N];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int sum=0,r=i+x-1;
		sum=c[r]-c[i];
		sum-=(s[r-1]-s[i-1])*(i-1);
		if(sum<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		c[i+1]=c[i]+i*b[i];
		s[i]=s[i-1]+b[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)==true) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

14 13
3 5 5 8 12 12 13 14 15 15 15 16 17 17 

5 8
-3 -1 2 2 7
*/
