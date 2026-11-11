#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl "\n"
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define fford(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define inf 1e15
using namespace std;
const int N=5e5+5;

int n,m,v[N],sum[N],ans=-inf;

bool check(int r,int i){
	return (i-r+1)*v[i]-sum[i]+sum[r-1]<=m;
}

signed main(){
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ffor(i,1,n) cin>>v[i];
    sort(v+1,v+n+1);
    ffor(i,1,n) sum[i]=sum[i-1]+v[i];
    int l,r,mid;
    ffor(i,1,n){
    	l=0,r=i+1;
    	while(l+1<r){
    		mid=(l+r)>>1;
    		if(check(mid,i)) r=mid;
    		else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
}

