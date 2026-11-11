#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
using namespace std;

const int N=5e5+10;
ll n,m,a[N],l,r,cst,ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	l=1,r=0;
	while(r<n){
		if(cst<=m) ans=max(ans,r-l+2);
		else {
			while(cst>m){
				cst-=a[r+1]-a[l];
				l++;
			}
			ans=max(ans,r-l+2);
		}
		r++;
		cst+=(a[r+1]-a[r])*(r-l+1);
	}
	cout<<ans;
	return 0; 
} 
