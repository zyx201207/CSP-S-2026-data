#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0,l=0,cost=0;
	for(int r=1;r<=n;r++){
		if(r>1)cost+=(r-l-1)*(a[r]-a[r-1]);
		while(l<r&&cost>m)cost-=(a[r]-a[++l]);
		ans=max(ans,r-l);
	}
	cout<<ans;
}
