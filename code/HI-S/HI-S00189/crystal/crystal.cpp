#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int n,m,a[N],b[N],c[N],d[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=b[i]+c[i-1];
	}
	int ans=0,sum=0;
	for(int l=1,r=2;r<=n;r++){
		if(b[r]*(r-l)+sum<=m){
			ans=max(ans,r-l+1);
			sum+=b[r]*(r-l);
		}
		else{			
			sum-=c[r-1]-c[l];
			l++,r--;
		}
	}
	cout << ans;
	return 0;
}

