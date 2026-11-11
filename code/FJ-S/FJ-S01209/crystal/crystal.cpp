#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,a,b) for(int i=a;i<=b;i++) 
const int N=5e5+5;
int n,m,a[N],b[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	ulp(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	int l=1,cnt=0;
	ulp(r,1,n){
		cnt+=(r-l)*(a[r]-a[r-1]);
		while(cnt>m){
			cnt-=a[r]-a[l];
			++l;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
