#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N],l=1;
__int128 sum[N];
ll check(int x){
	__int128 p=sum[x]-sum[l-1];
	__int128 c=1LL*(x-l+1)*a[x];
	while(c-p>m){
		l++;
		c=1LL*(x-l+1)*a[x];
		p=sum[x]-sum[l-1];
	}
	return x-l+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
    	sum[i]=sum[i-1]+a[i];
	}
    ll ans=0;
    for(int i=1;i<=n;i++){
    	ll res=check(i);
    	ans=max(ans,res);
	}
	cout<<ans<<endl;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
