#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=5e5+10;
int n,m,s[N],a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin>>n>>m;
	s[0]=0;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	int res=0;
	rep(i,1,n){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(m>=(i-mid+1)*a[i]-(s[i]-s[mid-1])){
				ans=mid,r=mid-1;
			}
			else l=mid+1;
		}
		res=max(res,i-ans+1);
	}
//	cout<<n*a[n]-(s[n]-s[0])<<"\n";
	cout<<res<<"\n";
	return 0;
} 
/*
5 5
1 2 4 8 9
ans£º3 

5 8
-3 -1 2 2 7
ans:4 
*/ 
