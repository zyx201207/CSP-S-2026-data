#include<bits/stdc++.h>
#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define R(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans=1;
int solve(int x){
	int l=1,r=x,ans=x;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-(s[x]-s[mid-1])<=m) r=mid-1,ans=mid;
		else l=mid+1;
	}return x-ans+1; 
}signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin>>n>>m;F(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);F(i,1,n) s[i]=a[i]+s[i-1];
	F(i,1,n) ans=max(ans,solve(i));
	return cout<<ans,0;
}
