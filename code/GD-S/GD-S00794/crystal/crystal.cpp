#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=500005;
int n,m,a[N],s[N],res=1;
inline bool check(int x,int y){
	return a[y]*x-s[y]+s[y-x]<=m;
}
signed main(){
#ifndef XYZ
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i))ans=mid,l=mid+1;
			else r=mid-1;
		}
		res=max(res,ans);
	}
	cout<<res;
	return 0;
}

