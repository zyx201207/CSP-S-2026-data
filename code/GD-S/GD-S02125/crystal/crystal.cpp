#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=5e5+5; 
int n,m,a[maxn],s[maxn];
int query(int l,int r){
	return s[r]-s[l-1];
}
int calc(int l,int r,int val){
	return (r-l+1)*val-query(l,r);
}
int res;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,ans=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(calc(mid,i-1,a[i])<=m){
				ans=i-mid+1;
				r=mid-1;
			}
			else l=mid+1;
		}
		res=max(res,ans);
	}
	cout<<res;
	return 0;
}

