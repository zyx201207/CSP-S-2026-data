#include<bits/stdc++.h>
#define N 500005
#define int long long
#define rep(i,a,b)     for(int i=(a);i<=(b);i++)
using namespace std;
int n,ans,m,a[N],s[N];
bool check(int l,int r){
	return s[r]-s[l-1]+m>=a[r]*(r-l+1);
}
signed main(){
   	ios::sync_with_stdio(0);
   	cin.tie(0);
  	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n)	cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n)	s[i]=a[i]+s[i-1];
	for(int i=n;i>0;i--){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,i))	r=mid;
			else	l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

