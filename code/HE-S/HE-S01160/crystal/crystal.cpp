#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r,x) for(int i=(l);i<=(r);i+=(x))
#define per(i,r,l,x) for(int i=(r);i>=(l);i-=(x))
using namespace std;
const int N=1e6+5;
int n,m,ans,sum;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n,1){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	ans=1;
	rep(r,2,n,1){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/
